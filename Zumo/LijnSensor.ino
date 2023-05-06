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

#include "LijnSensor.h"

/*! Constructor die nu niets doet. */
LijnSensor::LijnSensor() {

}

/*! Vertelt de Zumo dat alle vijf de lijnsensoren gebruikt moeten worden. */
void LijnSensor::sensoren_initialiseren() {
  lijnSensoren.initFiveSensors();
}

/*! Calibratie door metingen uit te lezen van de lijnsensoren en vervolgens te bepalen wat "licht" en "donker" is. */
void LijnSensor::sensoren_calibreren() {
  lijnSensoren.calibrate();
}

/*! Geeft aan hoever de Zumo van het midden van de lijn zit. */
int LijnSensor::lijn_positie() {
  return lijnSensoren.readLine(lijnSensorWaarden);
}
