#include<Wire.h>
#include"Wheel.h"
#include "LightSensor.h"
#include "UltrasoundSensor.h"

#include <stdlib.h>
#include <stdio.h>

void turnPerpendHoraire();
void setVitesse(uint8_t vitesse);
void  turnRight();
void straight(boolean sens_marche );
void setSens(uint8_t sens);
boolean isEqualSensor();




#define DIST_REF 20
#define PrecTurn 2 /*précison des distances lorsque l'on tourne à 90°*/

/*Capteur gauche*/
int pinTrigL = 4;
int pinEchoL = 7;

/*Capteur devant*/
int pinTrigF = 2;
int pinEchoF = 3;

long temps;
int tours=0; /* compte le nombre de fois qu'il tourne à 90° */



const byte VITESSE_1 = 200;

//Constructor WheelLeft with pin_revolution pin_rotation 12 pin_pwm=10
Wheel wheelLeft(2, 12, 10);
//Constructor WheelLeft with pin_revolution pin_rotation 13 pin_pwm=11
Wheel wheelRight(3, 13, 11);

//Constructor sensorLeft
LightSensor sensorLeft(A0);
//Constructor sensorRight
LightSensor sensorRight(A1);

/*Définition des capteurs*/
UltraSoundSensor SensorLeft(pinTrigL, pinEchoL);
UltraSoundSensor SensorFront(pinTrigF, pinEchoF);


void setup() {

  delay(1000);
  
  Serial.begin(9600);
  setVitesse(80);
  /*followLight();*/
  
  pinMode(pinTrigL, OUTPUT);
  pinMode(pinEchoL, INPUT);
 
  digitalWrite(pinTrigL, LOW);
  
  pinMode(pinTrigF, OUTPUT);
  pinMode(pinEchoF, INPUT);
 
  digitalWrite(pinTrigF, LOW);

  //straight(1);
}

void loop() {
  float distanceFront;
  //straight(1);
  distanceFront=SensorFront.getDistance();
  Serial.print("Distance devant: ");
  Serial.print(distanceFront);
  Serial.println(" cm");
  Serial.print("Distance gauche: ");
  Serial.print(SensorLeft.getDistance());
  Serial.println(" cm");
 
  if (distanceFront < 25){
    turnPerpendHoraire();
  }
}


void turnPerpendHoraire(){
  float distanceLeft;
  float ecartUltrason=0.73;
  float distanceFront=SensorFront.getDistance();
  
  stopWheel();
  Serial.print("Distance avant de ref: ");
  Serial.print(distanceFront);
  Serial.println(" cm");
  do
  {
   distanceLeft=SensorLeft.getDistance();
   Serial.print("Distance gauche: ");
   Serial.print(distanceLeft);
   Serial.println(" cm");
   turnRight();
  }while( (distanceLeft < distanceFront-ecartUltrason-0.25) || (distanceLeft > distanceFront-ecartUltrason+0.25) );
  stopWheel();
}

void setVitesse(uint8_t vitesse) {
  wheelLeft.setVitesse(vitesse);
  wheelRight.setVitesse(vitesse);
}

void  turnRight() {
  wheelLeft.setSens(1);
  wheelLeft.straight();

  wheelRight.setSens(0);
  wheelRight.straight();
}

void turnLeft() {
  wheelLeft.setSens(0);
  wheelLeft.straight();

  wheelRight.setSens(1);
  wheelRight.straight();
}

void stopWheel() {
  wheelLeft.pause();
  wheelRight.pause();

}
void setSens(uint8_t sens) {
  wheelLeft.setSens(sens);
  wheelRight.setSens(sens);
}
void straight(boolean sens_marche ) {
  wheelRight.setSens(sens_marche); //1 = farward, 0 backward
  wheelLeft.setSens(sens_marche);

  wheelLeft.straight();
  wheelRight.straight();
}

boolean isEqualSensor() {
  int seuil = 50;
  boolean isEqual;

  isEqual = false;
  int prevLumL = analogRead(sensorLeft.getLight());
  int prevLumR = analogRead(sensorRight.getLight());

  if (prevLumL - prevLumR < seuil && prevLumL - prevLumR > -seuil) {
    isEqual = true;
  }

  return isEqual;
}

/*
/////////Code chicane une fois qu'il à tourné à 90°////////////////

////// Avec turnRight

void loop(){
   float distanceLeft;
   straight(1);
   delay(2000); // pour passer la porte et pas avoir de problème avec le capteur gauche
   if(distanceLeft < 8){
    while(distanceLeft < 8){
      turnRight();
      straight();
    }
   }
   else if(distanceLeft > 15){
    while(distanceLeft > 15){
      turnLeft();
      straight();
    }
   }
   distanceLeft=SensorLeft.getDistance();
}



////// Ou avec changement vitesse roue

void loop(){
   float distanceLeft;
   int vitesseRobot;
   bool chicane=0;
   
   vitesseRobot=60;
   setVitesse(vitesseRobot);
   straight(1);
   if(chicane == 1){ si on a tourné devant la chicane 
      delay(2000); // pour passer la porte et pas avoir de problème avec le capteur gauche
      chicane=0;
   }
   if(distanceLeft < 8){
    while(distanceLeft < 8){
      wheelLeft.setVitesse(70);
      straight();
    }
   }
   else if(distanceLeft > 15){
    while(distanceLeft > 15){
      wheelRight.setVitesse(70);
      straight();
    }
   }
   distanceLeft=SensorLeft.getDistance();
   delay(500); // pour une prise de valeur que toute les 1/2 sec
}

*/
