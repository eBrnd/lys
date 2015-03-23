#include <string.h>

#include "fade.h"

#include "pwm.h"
#include "timer.h"

struct color_hsv fade_target = { 0, 0, 255 };
struct color_hsv fade_start = { 0, 0, 255 };
unsigned fade_steps_left = 0;
unsigned fade_duration = 1;

// Setup: Register timer.
void fade_setup() {
	timer_register_periodic(fade_step, 10);
}

// Set the value to fade to.
void fade_set_target(struct color_hsv* new_target, unsigned duration) {
	pwm_get_hsv(&fade_start);
	memcpy(&fade_target, new_target, sizeof(fade_target));
	if (duration == 0) duration = 1;
	fade_duration = fade_steps_left = duration;
}

// This should be called in more or less regular intervals and it does the actual fading.
void fade_step() {
	if(fade_steps_left) {
		fade_steps_left--;

		float fade_delta_t = 1.f - ((float)fade_steps_left / (float)fade_duration);

		struct color_hsv next_color = {
			(float)fade_start.h + fade_delta_t * ((float)fade_target.h - (float)fade_start.h),
			(float)fade_start.s + fade_delta_t * ((float)fade_target.s - (float)fade_start.s),
			(float)fade_start.v + fade_delta_t * ((float)fade_target.v - (float)fade_start.v)
		};

		pwm_set_hsv(&next_color);
	}
}
