#ifndef FADE_H_0C8331E280
#define FADE_H_0C8331E280

#include "color.h"

void fade_set_target(struct color_hsv* new_target);
void fade_step();

#endif
