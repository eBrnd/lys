#ifndef _IR_H_F39FLK7J1F
#define _IR_H_F39FLK7J1F

#include <stdbool.h>
#include <stdint.h>

#define INTERRUPT_PORT PCIE2
#define INTERRUPT_PIN PCINT23

struct ir_command_t {
	uint8_t address;
	uint8_t command;
	bool	repeat;
	bool	valid;
};

void ir_setup();
void ir_get_last_command();

#endif