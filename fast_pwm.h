#ifndef FAST_PWM_H
#define FAST_PWM_H
#include <avr/io.h>
#include <util/delay.h> //Library to include Delay function

enum mode_pwm{
  Fast_pwm_mode14 = 0,
  Fast_pwm_8bit,
  Fast_pwm_9bit,
  Fast_pwm_10bit
};

void initPWM(uint8_t mode);
void setPinsPWM(void);
void setDutyCycle(uint16_t dutyCycle,uint16_t top, uint8_t mode);
void setFrequency(uint8_t freq);

#endif
