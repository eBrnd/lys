#include <avr/interrupt.h>
#include <avr/pgmspace.h>

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

// Forward declarations.
void setup_port();
void setup_timer();

// Logarithm table for smoother visual appearance.
const uint16_t pwmtable[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
  6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 13, 13,
  13, 14, 14, 15, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  26, 26, 27, 28, 29, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 47, 48,
  49, 51, 52, 53, 55, 56, 58, 60, 61, 63, 65, 66, 68, 70, 72, 74, 76, 78, 80, 82, 85, 87, 89, 92,
  94, 97, 100, 102, 105, 108, 111, 114, 117, 121, 124, 127, 131, 134, 138, 142, 146, 150, 154, 158,
  162, 167, 171, 176, 181, 186, 191, 196, 202, 207, 213, 219, 225, 231, 237, 244, 250, 257, 264,
  271, 279, 287, 294, 303, 311, 319, 328, 337, 346, 356, 366, 376, 386, 397, 407, 419, 430, 442,
  454, 467, 479, 493, 506, 520, 534, 549, 564, 579, 595, 612, 628, 646, 663, 682, 700, 719, 739,
  760, 780, 802, 824, 846, 870, 893, 918, 943, 969, 996, 1023
};

// Setup - call this at boot time.
void pwm_setup() {
  r = g = b = 0;
  setup_port();
  setup_timer();
}

// Set PWM - set new value for the PWM.
void pwm_set(struct color_hsv* ch) {
  struct color_rgb cr;

  color_hsv2rgb(ch, &cr);

  r = pgm_read_word(&pwmtable[cr.r]);
  g = pgm_read_word(&pwmtable[cr.g]);
  b = pgm_read_word(&pwmtable[cr.b]);
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
