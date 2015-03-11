#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "timer.h"

#define TICKS_PER_MS F_CPU/1024/1000

static struct timer_task_t* task_chain_begin = NULL;
static struct timer_task_t* task_chain_end = NULL;

static volatile uint16_t time_passed = 0;

void timer_setup() {
	TCCR2A |= (1 << WGM21);
	TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
	OCR2A  |= TICKS_PER_MS;
	TIMSK2 |= (1 << OCIE2A);
}

void timer_remove_task(struct timer_task_t* task) {
	if(task->previous != NULL)
		task->previous->next = task->next;
	else
		task_chain_begin = task->next;

	if(task->next != NULL)
		task->next->previous = task->previous;
	else
		task_chain_end = task->previous;

	free(task);
}

void timer_run_tasks() {
	uint16_t passed = time_passed;
	time_passed = 0;

	struct timer_task_t* task = task_chain_begin;

	while(task != NULL) {
		task->time_since_last += passed;

		if(task->time_since_last >= task->delay) {
			task->callback();
			task->time_since_last = 0;

			if(task->once) {
				timer_remove_task(task);
			}
		}

		task = task->next;
	}
}

struct timer_task_t* timer_register_periodic(timer_callback_t callback, uint16_t delay) {
	task_chain_end->next = malloc(sizeof(struct timer_task_t));

	task_chain_end->next->callback = callback;
	task_chain_end->next->once = false;
	task_chain_end->next->delay = delay;
	task_chain_end->next->time_since_last = 0;
	task_chain_end->next->next = NULL;
	task_chain_end->next->previous = task_chain_end;

	task_chain_end = task_chain_end->next;

	if(task_chain_begin == NULL)
		task_chain_begin = task_chain_end;

	return task_chain_end;
}

void timer_register_single(timer_callback_t callback, uint16_t delay) {
	struct timer_task_t* task = timer_register_periodic(callback, delay);
	task->once = true;
}

ISR(TIMER2_COMPA_vect) {
	time_passed++;
}