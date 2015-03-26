#include <stdlib.h>
#include <stdbool.h>

#include "pwm.h"
#include "fade.h"
#include "color.h"
#include "program.h"
#include "timer.h"

struct color_hsv color_buffer = { 0, 0, 255 };
const unsigned default_fade_duration = 1000;

bool fire_running = false;

void program_setup() {
	pwm_set_hsv(&color_buffer);
}

void program_on() {
	fire_running = false;
	fade_set_target(&color_buffer, default_fade_duration);
	fire_running = false;
}

void program_off() {
	fire_running = false;
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
	fire_running = false;
	color_buffer.h = hue;
	color_buffer.s = saturation;

	fade_set_target(&color_buffer, default_fade_duration);
}

void program_brightness_increase(uint8_t steps) {
	fire_running = false;
	pwm_get_hsv(&color_buffer);
	if(steps > 255 - color_buffer.v) {
		color_buffer.v = 255;
	} else {
		color_buffer.v += steps;
	}

	fade_set_target(&color_buffer, 10);
}

void program_brightness_decrease(uint8_t steps) {
	fire_running = false;
	pwm_get_hsv(&color_buffer);
	if(steps > 240 || steps + 15 > color_buffer.v) {
		color_buffer.v = 15;
	} else {
		color_buffer.v -= steps;
	}

	fade_set_target(&color_buffer, 10);
}


void fire_step() {
	if (fire_running) {
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
	fire_running = true;
	timer_register_single(fire_step, 100);
}
