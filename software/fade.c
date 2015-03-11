#include <string.h>

#include "fade.h"

#include "pwm.h"

struct color_hsv fade_target = { 0, 0, 0 };

// Set the value to fade to.
void fade_set_target(struct color_hsv* new_target) {
  memcpy(&fade_target, new_target, sizeof(fade_target));
}

// This should be called in more or less regular intervals and it does the actual fading.
void fade_step() {
  static struct color_hsv color_now;

  pwm_get_hsv(&color_now);

  if (color_now.h > fade_target.h)
    color_now.h--;
  else if (color_now.h < fade_target.h)
    color_now.h++;

  if (color_now.s > fade_target.s)
    color_now.s--;
  else if (color_now.s < fade_target.s)
    color_now.s++;

  if (color_now.v > fade_target.v)
    color_now.v--;
  else if (color_now.v < fade_target.v)
    color_now.v++;

  pwm_set_hsv(&color_now);
}
