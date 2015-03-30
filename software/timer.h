#ifndef TIMER_H_A9WEV71MW0
#define TIMER_H_A9WEV71MW0

#include <stdint.h>
#include <stdbool.h>

typedef void (*timer_callback_t)(void);

struct timer_task_t {
	timer_callback_t callback;
	bool once;
	uint16_t delay;
	uint16_t time_since_last;
	struct timer_task_t* next;
	struct timer_task_t* previous;
};

void timer_setup();
void timer_remove_task(struct timer_task_t* task);
void timer_run_tasks();
struct timer_task_t* timer_register_periodic(timer_callback_t callback, uint16_t delay);
void timer_register_single(timer_callback_t callback, uint16_t delay);

#endif
