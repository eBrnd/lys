#include <stdlib.h>
#include <stdbool.h>

#include "pwm.h"
#include "fade.h"
#include "color.h"
#include "program.h"
#include "timer.h"

struct color_hsv color_buffer = { 0, 0, 255 };
const unsigned default_fade_duration = 20;

enum Program {
	Program_STATIC, Program_FIRE, Program_WATER, Program_FOREST
};

enum Program current_program = Program_STATIC;

void program_setup() {
	fade_setup();
	pwm_set_hsv(&color_buffer);
}

void program_on() {
	current_program = Program_STATIC;
	fade_set_target(&color_buffer, default_fade_duration);
}

void program_off() {
	current_program = Program_STATIC;
	pwm_get_hsv(&color_buffer);
	uint8_t vtemp = color_buffer.v;
	color_buffer.v = 0;
	fade_set_target(&color_buffer, default_fade_duration);
	color_buffer.v = vtemp; // so that the correct v is set when we do program_on again.
}

void program_static(uint16_t hue, uint8_t saturation) {
	// TODO this will not work as long as fade is active --- make it to something like
	// fade set target speed infinity, as soon as we can set fade speed
	color_buffer.h = hue;
	color_buffer.s = saturation;

	pwm_set_hsv(&color_buffer);
}

void program_fade_static(uint16_t hue, uint8_t saturation) {
	current_program = Program_STATIC;
	color_buffer.h = hue;
	color_buffer.s = saturation;

	fade_set_target(&color_buffer, default_fade_duration);
}

void program_brightness_increase(uint8_t steps) {
	current_program = Program_STATIC;
	pwm_get_hsv(&color_buffer);
	if(steps > 255 - color_buffer.v) {
		color_buffer.v = 255;
	} else {
		color_buffer.v += steps;
	}

	fade_set_target(&color_buffer, 10);
}

void program_brightness_decrease(uint8_t steps) {
	current_program = Program_STATIC;
	pwm_get_hsv(&color_buffer);
	if(steps > 240 || steps + 15 > color_buffer.v) {
		color_buffer.v = 15;
	} else {
		color_buffer.v -= steps;
	}

	fade_set_target(&color_buffer, 10);
}

static void fire_step() {
	if (current_program == Program_FIRE) {
		struct color_hsv color = {
			random() % 256, 255, random() % 256
		};

		if (color.h > 192)
			color.h += 1536-256;

		unsigned duration = random() % 192;

		if (color.v < 128) // Get darker more quickly.
			duration /= 2;

		fade_set_target(&color, duration);

		timer_register_single(fire_step, 10 * duration);
	}
}

void program_fire() {
	current_program = Program_FIRE;
	timer_register_single(fire_step, 1);
}

static void water_step() {
	if (current_program == Program_WATER) {
		struct color_hsv color = {
			640 + random() % 512, 32 + random() % 224, 128 + random() % 128
		};

		unsigned duration = 128 + random() % 284;

		fade_set_target(&color, duration);

		timer_register_single(water_step, 10 * duration);
	}
}

void program_water() {
	current_program = Program_WATER;
	timer_register_single(water_step, 1);
}

static void forest_step() {
	if (current_program == Program_FOREST) {
		struct color_hsv color = {
			192 + random() % 512, 192 + random() % 64, 128 + random() % 128
		};

		unsigned duration = 128 + random() % 768;

		fade_set_target(&color, duration);

		timer_register_single(forest_step, 10 * duration);
	}
}

void program_forest() {
	current_program = Program_FOREST;
	timer_register_single(forest_step, 1);
}

