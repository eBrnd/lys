#include <stdlib.h>
#include <string.h>

#include "fade.h"

#include "pwm.h"
#include "timer.h"

struct color_hsv fade_target = { 0, 0, 255 };
struct color_hsv fade_start = { 0, 0, 255 };
int32_t fade_diff_h, fade_diff_s, fade_diff_v;
unsigned fade_steps = 0;
unsigned fade_duration = 1;

// Setup: Register timer.
void fade_setup() {
	pwm_setup();
	timer_register_periodic(fade_step, 10);
}

// Set the value to fade to.
void fade_set_target(struct color_hsv* new_target, unsigned duration) {
	pwm_get_hsv(&fade_start);
	memcpy(&fade_target, new_target, sizeof(fade_target));

	if (duration == 0)
		duration = 1;
	fade_duration = duration;
	fade_steps = 0;
	fade_diff_h = (int32_t)fade_target.h - (int32_t)fade_start.h;
	fade_diff_s = (int32_t)fade_target.s - (int32_t)fade_start.s;
	fade_diff_v = (int32_t)fade_target.v - (int32_t)fade_start.v;

	if (fade_diff_h > 1536/2)
		fade_diff_h -= 1536;
	else if (fade_diff_h < -1536/2)
		fade_diff_h += 1536;
}

// This should be called in more or less regular intervals and it does the actual fading.
void fade_step() {
	if(fade_steps < fade_duration) {
		fade_steps++;

		struct color_hsv next_color = {
			((int32_t)fade_start.h + ((fade_steps * fade_diff_h) / fade_duration) + 1536) % 1536,
			(int32_t)fade_start.s + ((fade_steps * fade_diff_s) / fade_duration),
			(int32_t)fade_start.v + ((fade_steps * fade_diff_v) / fade_duration)
		};

		pwm_set_hsv(&next_color);
	}
}
