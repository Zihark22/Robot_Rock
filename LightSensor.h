#ifndef LightSensor_h
#define LightSensor_h
#include "Arduino.h"


class LightSensor
{
public:
  uint16_t photoResistance;
  uint16_t pin_resistance;

  uint16_t store_v_t[ ][2];

  LightSensor(int pin_resistance);
  uint16_t getLight();

};




#endif
