#include <util/delay.h>
#include <avr/interrupt.h>

#include "pwm.h"
#include "fade.h"
#include "ir.h"
#include "timer.h"
#include "remote.h"
#include "program.h"

void setup() {
  pwm_setup();
  ir_setup();
  timer_setup();
  fade_setup();
  program_setup();
}

int main() {
  setup();

  for(;;) {
    remote_handle_commands();
    timer_run_tasks();
  }

  return 0;
}
