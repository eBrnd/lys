#include <util/delay.h>
#include <avr/interrupt.h>

// PWM Port.
#define PWM_PORT PORTC
#define PWM_DDR DDRC

// PWM Pins.
#define PR PC1
#define PG PC2
#define PB PC3

void setup_port() {
  PWM_DDR = (1 << PR) | (1 << PG) | (1 << PB);
}

void setup_timer() {
  TCCR1A |= (1 << WGM10); // 8 bit.
  TCCR1B |= (1 << CS10) | (1 << WGM13); // Compare with OCR1A.
  TIMSK1 |= (1 << TOIE1); // Enable timer overflow interrupt.

  OCR1A = 64;
}

// Globals storing PWM values.
unsigned char r, g, b;

void do_pwm() {
  static unsigned char count = 0;
  count++;

  if(count < r)
    PWM_PORT |= (1 << PR);
  else
    PWM_PORT &= ~(1 << PR);

  if(count < g)
    PWM_PORT |= (1 << PG);
  else
    PWM_PORT &= ~(1 << PG);

  if(count < b)
    PWM_PORT |= (1 << PB);
  else
    PWM_PORT &= ~(1 << PB);
}

int main() {
  cli();
  setup_port();
  setup_timer();
  sei();

  r = g = b = 0;

  for(;;) {
    r++; g++; b++;
    _delay_ms(100);
  }
}

ISR(TIMER1_OVF_vect) {
  do_pwm();
}
