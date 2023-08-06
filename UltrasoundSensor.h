#ifndef UltrasoundSensor_h
#define UltrasoundSensor_h
#include "Arduino.h"


class UltraSoundSensor
{
public:
  uint8_t pin_trig;
  uint8_t pin_echo;

  UltraSoundSensor(int pin_trig, int pin_echo);
  float getDistance();



};




#endif
