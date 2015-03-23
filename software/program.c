#include "pwm.h"
#include "fade.h"
#include "color.h"
#include "program.h"

struct color_hsv color_buffer = { 0, 0, 255 };

void program_setup() {
	pwm_set_hsv(&color_buffer);
}

void program_run() {}

void program_on() {
	pwm_set_hsv(&color_buffer);
}

void program_off() {
	struct color_hsv color_off = {
		color_buffer.h,
		color_buffer.s,
		0
	};

	pwm_set_hsv(&color_off);
}

void program_static(uint16_t hue, uint8_t saturation) {
	color_buffer.h = hue;
	color_buffer.s = saturation;

	pwm_set_hsv(&color_buffer);
}

void program_fade_static(uint16_t hue, uint8_t saturation) {
	color_buffer.h = hue;
	color_buffer.s = saturation;

	fade_set_target(&color_buffer);
}

void program_brightness_increase(uint8_t steps) {
	pwm_get_hsv(&color_buffer);
	if(steps > 255 - color_buffer.v) {
		color_buffer.v = 255;
	} else {
		color_buffer.v += steps;
	}

	fade_set_target(&color_buffer);
}

void program_brightness_decrease(uint8_t steps) {
	pwm_get_hsv(&color_buffer);
	if(steps > 240 || steps + 15 > color_buffer.v) {
		color_buffer.v = 15;
	} else {
		color_buffer.v -= steps;
	}

	fade_set_target(&color_buffer);
}

void program_speed_increase(uint8_t steps) {}
void program_speed_decrease(uint8_t steps) {}

void program_flash() {}
void program_fade() {}
