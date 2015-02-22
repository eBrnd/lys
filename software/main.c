#include "pwm.h"

#include <util/delay.h>

int main() {
  pwm_setup();

  for(;;) {
    pwm_set();
    _delay_ms(5);
  }
}

