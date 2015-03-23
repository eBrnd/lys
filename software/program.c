#include "pwm.h"
#include "fade.h"
#include "color.h"
#include "program.h"

struct color_hsv color_buffer = { 0, 0, 255 };
const unsigned default_fade_duration = 1000;

void program_setup() {
	pwm_set_hsv(&color_buffer);
}

void program_run() {}

void program_on() {
	fade_set_target(&color_buffer, default_fade_duration);
}

void program_off() {
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
	color_buffer.h = hue;
	color_buffer.s = saturation;

	fade_set_target(&color_buffer, default_fade_duration);
}

void program_brightness_increase(uint8_t steps) {
	pwm_get_hsv(&color_buffer);
	if(steps > 255 - color_buffer.v) {
		color_buffer.v = 255;
	} else {
		color_buffer.v += steps;
	}

	fade_set_target(&color_buffer, 10);
}

void program_brightness_decrease(uint8_t steps) {
	pwm_get_hsv(&color_buffer);
	if(steps > 240 || steps + 15 > color_buffer.v) {
		color_buffer.v = 15;
	} else {
		color_buffer.v -= steps;
	}

	fade_set_target(&color_buffer, 10);
}

void program_speed_increase(uint8_t steps) {}
void program_speed_decrease(uint8_t steps) {}

void program_flash() {}
void program_fade() {}
