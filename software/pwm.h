#ifndef PWM_H_AF75A7E1C0
#define PWM_H_AF75A7E1C0

#include "color.h"

void pwm_setup();
void pwm_set(struct color_hsv* ch);
void pwm_get(struct color_hsv* ch);

#endif
