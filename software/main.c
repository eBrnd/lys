#include "pwm.h"
#include "fade.h"
#include "ir.h"

#include <util/delay.h>

int main() {
  pwm_setup();
  ir_setup();

  struct color_hsv fade_target = { 0, 255, 255 };
  fade_set_target(&fade_target);
  uint16_t c = 0;

  for(;;) {

    _delay_ms(25);
    fade_step();
    c++;
    if (c == 300) {
      fade_target.h = 1000;
      fade_set_target(&fade_target);
    }
    if (c == 1500) {
      fade_target.v = 0;
      fade_set_target(&fade_target);
    }
    if (c == 1800) {
      fade_target.v = 255;
      fade_target.s = 0;
      fade_set_target(&fade_target);
    }
    if (c == 2100) {
      fade_target.h = 0;
      fade_target.s = fade_target.v = 255;
      fade_set_target(&fade_target);
    }
    if (c == 2400)
      c = 0;
  }
}

