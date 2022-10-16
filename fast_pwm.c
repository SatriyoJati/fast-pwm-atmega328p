#include "fast_pwm.h"
/*
OC2B PD3 -- digital pin 3
OC2A PB3 -- digital pin 11
OC1B PB2 -- digital pin 2
OC1A PB1 -- digital pin 9
OC0B PD5 -- digital pin 5
OC0A PD6 -- digital pin 6
*/

void setDutyCycle(uint16_t dutyCycle,uint16_t top, uint8_t mode){
  if(mode == 0){
    ICR1 = top;
    OCR1A = dutyCycle;
  }else{
    OCR1A = dutyCycle;
  }

}

void initPWM(uint8_t mode)
{
  TCCR1A = 0;
  TCCR1B = 0;
  DDRB = 0;
  DDRB |= _BV(PB1);
  switch (mode){
    case Fast_pwm_mode14:
      TCCR1A |= _BV(COM1A1)| //set non inverting mode
                _BV(WGM11);   //set FastForward Mode 14

      TCCR1B |= _BV(WGM13) |
                _BV(WGM12) |
                _BV(CS11);
                // _BV(CS10);      //prescaler 8
              break;

    case Fast_pwm_8bit:
      TCCR1A |= _BV(COM1A1)| //set non inverting mode
                _BV(WGM10);   //set FastForward 8 bit

      TCCR1B |= _BV(WGM12) |
                _BV(CS11);
                // _BV(CS10);    //prescaler 8
                break;

    case Fast_pwm_9bit:
      TCCR1A |= _BV(COM1A1)| //set non inverting mode
                _BV(WGM11);   //set FastForward 9 bit

      TCCR1B |= _BV(WGM12) |
                _BV(CS11);
                break;

    case Fast_pwm_10bit:
      TCCR1A |= _BV(COM1A1)| //set non inverting mode
                _BV(WGM11) |  //set FastForward 10 bit
                _BV(WGM10);
      TCCR1B |= _BV(WGM12) |
                  _BV(CS10);
                break;
  }

}
