#include <avr/interrupt.h>
#include <util/delay.h>

#include "ir.h"

#include "uart.h"

// Timer interrupt shall run with 10kHz, prescaler is 8.
#define TIMER_TICKS F_CPU/80000

// States for IR protocol state machine.
enum ir_state_t {
	IDLE,
	PREAMBLE_H,
	PREAMBLE_L,
	DATA_H,
	DATA_L
};

// Global state variables for ISRs.
static volatile uint8_t ir_time = 0;
static volatile enum ir_state_t state = IDLE;

// Global variables to store last recognized command.
static volatile char last_data[2] = {0,0};
static volatile bool flag_valid = false;
static volatile bool flag_repeat = false;

// Setup - call this at boot time.
void ir_setup() {
	cli();
	//Pin interrupt
	PCICR  |= (1 << INTERRUPT_PORT);
	PCMSK2 |= (1 << INTERRUPT_PIN);

	//Timer
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01);
	OCR0A  |= TIMER_TICKS;
	sei();
}

// Read last recognized command.
void ir_get_last_command(struct ir_command_t* command) {
	PCICR  &= ~(1 << INTERRUPT_PORT);

	command->valid = flag_valid;
	command->repeat = flag_repeat;
	command->address = last_data[0];
	command->command = last_data[1];

	flag_valid = false;

	PCICR  |= (1 << INTERRUPT_PORT);
}

// ISRs for pin and timer interrupt.
ISR(PCINT2_vect) {
	PCICR  &= ~(1 << INTERRUPT_PORT);

	static volatile uint8_t bit = 0;
	static volatile uint32_t data = 0;

	switch(state) {
		case IDLE:
			TIMSK0 |= (1 << OCIE0A);
			state = PREAMBLE_H;
			break;
		case PREAMBLE_H:
			bit = 0;
			data = 0;
			// Preamble high lasts 9ms.
			if(ir_time>85 && ir_time<95) {
				state = PREAMBLE_L;
			} else {
				state = PREAMBLE_H;
			}
			break;
		case PREAMBLE_L:
			// Preamble is followed by an 4.5ms gap,
			if(ir_time>40 && ir_time<47) {
				state = DATA_H;

			// or 2.25ms for a repeat signal.
			// TODO: Check if a valid pulse follows.
			} else if(ir_time>20 && ir_time<25) {
				flag_repeat = true;
				flag_valid = true;
				state = PREAMBLE_H;
			} else {
				state = PREAMBLE_H;
			}
			break;
		case DATA_H:
			// Every data pulse lasts 560µS.
			if(ir_time>1 && ir_time<7) {
				state = DATA_L;
			} else {
				state = PREAMBLE_H;
			}
			break;
		case DATA_L:
			// A logical 0 has a 560µS gap in between,
			if(ir_time>1 && ir_time<7) {
				bit++;
				state = DATA_H;
			// for a logical 1 the gap lasts about 1.75ms.
			} else if(ir_time>14 && ir_time <19) {
				data |= ((uint32_t)1 << bit);
				bit++;
				state = DATA_H;
			} else {
				state = PREAMBLE_H;
			}

			// A complete command is 32 bits long.
			if(bit > 31) {
				char data_bytes[4] = {
					((char*)&data)[0],
					((char*)&data)[1],
					((char*)&data)[2],
					((char*)&data)[3]
				};

				// For a valid command every second byte is the inverse of the previous byte.
				if(!(data_bytes[0]&data_bytes[1])&&!(data_bytes[2]&data_bytes[3])) {
					last_data[0] = data_bytes[0];
					last_data[1] = data_bytes[2];
					flag_repeat = false;
					flag_valid = true;
				}

				state = PREAMBLE_H;
			}
			break;
	}

	TCNT0 = 0;
	ir_time = 0;

	PCICR  |= (1 << INTERRUPT_PORT);
}

ISR(TIMER0_COMPA_vect) {
	ir_time++;

	//Go to sleep on overflow.
	if(ir_time==0) {
		TIMSK0 &= ~(1 << OCIE0A);
		state = IDLE;
	}
}