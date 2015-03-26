#ifndef PROGRAM_H_F1L39JACOX
#define PROGRAM_H_F1L39JACOX

void program_setup();

void program_on();
void program_off();

void program_static(uint16_t hue, uint8_t saturation);
void program_fade_static(uint16_t hue, uint8_t saturation);

void program_brightness_increase(uint8_t steps);
void program_brightness_decrease(uint8_t steps);

void program_fire();

#endif
