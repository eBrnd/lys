#include <util/delay.h>
#include <avr/interrupt.h>

// PWM Port.
#define PWM_PORT PORTC
#define PWM_DDR DDRC

// PWM Pins.
#define PR PC3
#define PG PC1
#define PB PC2

void setup_port() {
  PWM_DDR = (1 << PR) | (1 << PG) | (1 << PB);
}

void setup_timer() {
  TCCR1A |= (1 << WGM10); // 8 bit.
  TCCR1B |= (1 << CS10) | (1 << WGM13); // Compare with OCR1A.
  TIMSK1 |= (1 << TOIE1); // Enable timer overflow interrupt.

  OCR1A = 128;
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

  uint32_t color_counter;
  r = g = b = 0;

  for(;;) {
    color_counter++;

    if(color_counter < 256) {
      g = b = 0;
      r = color_counter;
    } else if(color_counter < 512) {
      r = b = 0;
      g = color_counter - 256;
    } else {
      r = g = 0;
      b = color_counter - 512;
      if(color_counter == 767) 
        color_counter = 0;
    }
    _delay_ms(5);
  }
}

ISR(TIMER1_OVF_vect) {
  do_pwm();
}
