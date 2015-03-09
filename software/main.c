#include <util/delay.h>
#include <avr/interrupt.h>

#include "pwm.h"
#include "fade.h"
#include "ir.h"

void init_fade_timer() {
  TCCR2A |= (1 << WGM21);
  TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
  OCR2A  |= 30;
  TIMSK2 |= (1 << OCIE2A);
}

int main() {
  pwm_setup();
  ir_setup();

  init_fade_timer();

  struct color_hsv fade_target = {0, 255, 255};
  fade_set_target(&fade_target);

  struct ir_command_t cmd;

  fade_set_target(&fade_target);

  for(;;) {
    ir_get_last_command(&cmd);

    if(cmd.valid) {
      switch(cmd.command) {
        // Color keys
        case 25:
          fade_target.h = 0;
          fade_target.s = 255;
          break;
        case 23:
          fade_target.h = 64;
          fade_target.s = 255;
          break;
        case 64:
          fade_target.h = 128;
          fade_target.s = 255;
          break;
        case 10:
          fade_target.h = 192;
          fade_target.s = 255;
          break;
        case 28:
          fade_target.h = 255;
          fade_target.s = 255;
          break;
        case 27:
          fade_target.h = 512;
          fade_target.s = 255;
          break;
        case 18:
          fade_target.h = 576;
          fade_target.s = 255;
          break;
        case 76:
          fade_target.h = 640;
          fade_target.s = 255;
          break;
        case 30:
          fade_target.h = 704;
          fade_target.s = 255;
          break;
        case 20:
          fade_target.h = 768;
          fade_target.s = 255;
          break;
        case 17:
          fade_target.h = 1024;
          fade_target.s = 255;
          break;
        case 22:
          fade_target.h = 1088;
          fade_target.s = 255;
          break;
        case 4:
          fade_target.h = 1152;
          fade_target.s = 255;
          break;
        case 14:
          fade_target.h = 1216;
          fade_target.s = 255;
          break;
        case 15:
          fade_target.h = 1280;
          fade_target.s = 255;
          break;
        // White key
        case 21:
          fade_target.s = 0;
          break;
        // Brightness keys
        case 9:
          if(fade_target.v<255)
            fade_target.v+= 10;
          break;
        case 29:
          if(fade_target.v>15)
            fade_target.v-= 10;
          break;
        // On/Off keys
        case 31:
          fade_target.v = 0;
          break;
        case 13:
          fade_target.v = 255;
          break;
        default:;
      }
      fade_set_target(&fade_target);
    }
  }

  return 0;
}

ISR(TIMER2_COMPA_vect) {
  fade_step();
}