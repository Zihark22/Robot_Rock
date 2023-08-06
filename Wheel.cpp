#include "Arduino.h"
#include "Wheel.h"
using namespace std;

Wheel::Wheel(int pin_revolution, int pin_rotation, int new_pin_pwm) {
  this->vitesse = 0;

  this->coder = 0;
  this->pin_coder = pin_revolution;
  pinMode(pin_coder, INPUT);

  this->pin_rotation = pin_rotation;
  this->rotation = 1;
  pinMode(pin_rotation, OUTPUT);
  digitalWrite(this->pin_rotation, rotation);


  this->pin_pwm = new_pin_pwm;
  pwm = 0;
  pinMode(pin_pwm, OUTPUT);
}

void Wheel::setVitesse(uint8_t new_vitesse) {
  vitesse = new_vitesse;
}

void Wheel::setSens(uint8_t sens) {
  rotation = sens;
  digitalWrite(this->pin_rotation, rotation);
}

void Wheel::straight() {
  analogWrite(this->pin_pwm, vitesse);
}


void Wheel::pause() {
    analogWrite(pin_pwm, 0);
}
