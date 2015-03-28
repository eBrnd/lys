#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <string.h>

#include "pwm.h"

#include "color.h"

// PWM Port.
#define PWM_PORT PORTC
#define PWM_DDR DDRC

// PWM Pins.
#define PR PC3
#define PG PC1
#define PB PC2

// Globals storing PWM values.
uint16_t r, g, b;

// Global to cache last set color
struct color_hsv current_color = {0, 0, 0};

// Forward declarations.
void setup_port();
void setup_timer();
void set_rgb(struct color_rgb* cr);

// Setup - call this at boot time.
void pwm_setup() {
  r = g = b = 0;
  setup_port();
  setup_timer();
}

// Set PWM - set new value for the PWM.
void pwm_set_hsv(struct color_hsv* ch) {
  struct color_rgb cr;

  memcpy(&current_color, ch, sizeof(struct color_hsv));

  color_hsv2rgb(ch, &cr);

  set_rgb(&cr);
}

void set_rgb(struct color_rgb* cr) {
  r = cr->r * 4;
  g = cr->g * 4;
  b = cr->b * 4;
}

//Get current color
void pwm_get_hsv(struct color_hsv* ch) {
  memcpy(ch, &current_color, sizeof(struct color_hsv));
}

// This is run from the timer ISR.
static inline void do_pwm() {
  static uint16_t bit_index = 1;

  bit_index = (bit_index >> 9) | (bit_index << 1); // Rotate bit 1 to the left.
  // This generates some noise in the first 6 bits of the bit_index. We don't care about that
  // because the pwmtable always contains 0s there. And for TCNT1 it's not relevant cause the
  // 'noise' is shifted out anyways.

  TCNT1 = ~(bit_index << 6); // = 65535 (=timer top) - (bit_index << 5).

  unsigned char pwm_out = 0;
  if (r & (bit_index))
    pwm_out |= (1 << PR);
  if (g & (bit_index))
    pwm_out |= (1 << PG);
  if (b & (bit_index))
    pwm_out |= (1 << PB);

  PWM_PORT = pwm_out;
}

// ==== Setup helper functions. ====
void setup_port() {
  PWM_DDR = (1 << PR) | (1 << PG) | (1 << PB);
}

void setup_timer() {
  cli();
  TCCR1A |= 0;
  TCCR1B |= (1 << CS10);
  TIMSK1 |= (1 << TOIE1); // Enable timer overflow interrupt.

  OCR1A = 256;
  sei();
}

ISR(TIMER1_OVF_vect) {
  do_pwm();
}
// ==== ====
