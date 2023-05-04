/*!
  @file LijnSensor.ino
  @date 26 Apr 2023
  @author Ruben van Eijken

  Stukje code om de klasse uit LijnSensor.hpp te testen. Print de positie van de lijn ten opzichte van de Zumo naar de seriële poort.

  modified 26 Apr 2023
  by Ruben van Eijken
  modified 2 May 2023
  by Ruben van Eijken
*/

#include <Wire.h>
#include "LijnSensor.hpp"
#include <stdio.h>

LijnSensor lijnSensor;

void setup() {
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_calibreren();
}

void loop() {
  int positie = lijnSensor.lijn_positie();
  Serial.println(positie);
}
