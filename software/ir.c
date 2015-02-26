#include <avr/interrupt.h>
#include <util/delay.h>

#include "ir.h"

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
	OCR0A  |= 250;
	sei();
}

// Read last recognized command.
struct ir_command_t ir_get_last_command() {
	struct ir_command_t result;

	PCICR  &= ~(1 << INTERRUPT_PORT);

	result.valid = flag_valid;
	result.repeat = flag_repeat;
	result.address = last_data[0];
	result.command = last_data[1];

	PCICR  |= (1 << INTERRUPT_PORT);

	return result;
}

// ISRs for pin and timer interrupt.
ISR(PCINT2_vect) {
	static uint8_t bit = 0;
	static uint32_t data = 0;

	TCNT0 = 0;

	switch(state) {
		case IDLE:
			TIMSK0 |= (1 << OCIE0A);
			state = PREAMBLE_H;
			break;
		case PREAMBLE_H:
			if(ir_time>85 && ir_time<95) {
				state = PREAMBLE_L;
			} else {
				state = PREAMBLE_H;
			}
			break;
		case PREAMBLE_L:
			if(ir_time>40 && ir_time<50) {
				state = DATA_H;
			} else if(ir_time>15 && ir_time<25) {
				//Repeat
				flag_repeat = true;
				flag_valid = true;
				state = PREAMBLE_H;
			} else {
				state = PREAMBLE_H;
			}
			break;
		case DATA_H:
			if(ir_time>2 && ir_time<7) {
				state = DATA_L;
			} else {
				bit = 0;
				data = 0;
				state = PREAMBLE_H;
			}
			break;
		case DATA_L:
			if(ir_time>2 && ir_time<7) {
				bit++;
				state = DATA_H; // 0
			} else if(ir_time>14 && ir_time <19) {
				data |= ((uint32_t)1 << bit);
				bit++;
				state = DATA_H; // 1
			} else {
				bit = 0;
				data = 0;
				state = PREAMBLE_H;
			}

			if(bit > 31) {
				char data_bytes[4] = {
					((char*)&data)[0],
					((char*)&data)[1],
					((char*)&data)[2],
					((char*)&data)[3]
				};

				if(!(data_bytes[0]&data_bytes[1])&&!(data_bytes[2]&data_bytes[3])) {
					last_data[0] = data_bytes[0];
					last_data[1] = data_bytes[2];
					flag_repeat = false;
					flag_valid = true;
				}

				bit = 0;
				state = PREAMBLE_H;
			}
			break;
	}
	ir_time = 0;
}

ISR(TIMER0_COMPA_vect) {
	ir_time++;

	//Go to sleep on overflow.
	if(!ir_time) {
		TIMSK0 &= ~(1 << OCIE0A);
		state = IDLE;
	}
}