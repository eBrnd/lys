#include <util/delay.h>
#include <avr/interrupt.h>

#include "timer.h"
#include "user_input.h"
#include "program.h"

void setup() {
  timer_setup();
  user_input_setup();
  program_setup();
}

void periodic() {
  user_input_periodic();
  timer_run_tasks();
}

int main() {
  setup();

  for(;;) {
    periodic();
  }

  return 0;
}
