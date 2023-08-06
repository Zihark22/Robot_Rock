#ifndef Wheel_h
#define Wheel_h
#include "Arduino.h"


class Wheel
{
public:
  int vitesse;

  uint8_t coder;
  uint16_t pin_coder;
  
  uint8_t pin_rotation;
  boolean rotation;

  uint8_t pin_pwm;
  uint8_t pwm;


  Wheel(int pin_revolution, int pin_rotation, int pin_pwm);
  void setVitesse(uint8_t vitesse);
  void setSens(uint8_t sens);
  void straight();
  void pause();


};




#endif
