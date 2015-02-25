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
unsigned char r, g, b;

// Forward declarations.
void setup_port();
void setup_timer();

// Logarithm table for smoother visual appearance.
const uint8_t pwmtable[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8,
  9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 15,
  15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 19, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 23, 24, 24,
  25, 25, 26, 26, 27, 28, 28, 29, 29, 30, 31, 31, 32, 33, 34, 34, 35, 36, 37, 37, 38, 39, 40, 41,
  42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 62, 63, 65, 66, 67, 69,
  70, 72, 74, 75, 77, 79, 80, 82, 84, 86, 88, 89, 91, 93, 96, 98, 100, 102, 104, 107, 109, 111, 114,
  116, 119, 121, 124, 127, 130, 133, 135, 138, 141, 145, 148, 151, 154, 158, 161, 165, 172, 176,
  180, 184, 188, 192, 196, 201, 205, 210, 214, 219, 224, 229, 234, 239, 244, 249, 255
};

// Setup - call this at boot time.
void pwm_setup() {
  r = g = b = 0;
  setup_port();
  setup_timer();
}

// Set PWM - set new value for the PWM.
void pwm_set() {
  static unsigned color_counter = 0;
  if (++color_counter == 1536)
    color_counter = 0;

  struct color_hsv ch = { color_counter, 64, 196 };
  struct color_rgb cr;

  color_hsv2rgb(&ch, &cr);

  r = pgm_read_byte(&pwmtable[cr.r]);
  g = pgm_read_byte(&pwmtable[cr.g]);
  b = pgm_read_byte(&pwmtable[cr.b]);
}

// This is run from the timer ISR.
static inline void do_pwm() {
  static unsigned char bit_index = 1;

  bit_index = (bit_index >> 7) | (bit_index << 1); // Rotate bit 1 to the left.

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

  // Testing: How long does interrupt routine take?
  PWM_DDR |= (1 << PC5);
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
