#ifndef PWM_H_AF75A7E1C0
#define PWM_H_AF75A7E1C0

#include "color.h"

void pwm_setup();
void pwm_set_hsv(struct color_hsv* ch);
void pwm_set_rgb(struct color_rgb* cr);
void pwm_get_hsv(struct color_hsv* ch);
void pwm_get_rgb(struct color_rgb* cr);

#endif
