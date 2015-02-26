#include "pwm.h"
#include "ir.h"

#include <util/delay.h>

int main() {
  pwm_setup();
  ir_setup();

  for(;;) {
    pwm_set();
    _delay_ms(25);
  }
}

