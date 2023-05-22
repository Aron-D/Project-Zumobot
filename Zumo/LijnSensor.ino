/*!
  @file LijnSensor.ino
  @date 26 Apr 2023
  @author Ruben van Eijken

  Implementatie van de methodes in LijnSensor.h

  modified 26 Apr 2023
  by Ruben van Eijken
  modified 2 May 2023
  by Ruben van Eijken
*/

#include "LijnSensor.h"

/*! Vertelt de Zumo dat alle vijf de lijnsensoren gebruikt moeten worden. */
void LijnSensor::initialiseren() {
  lijnSensoren.initFiveSensors();
}

/*! Calibratie door metingen uit te lezen van de lijnsensoren en vervolgens te bepalen wat "licht" en "donker" is. */
void LijnSensor::kalibreren(const Motoren& motoren)
{
  for(uint16_t i = 0; i < 120; i++)
  {
    lijnSensoren.calibrate();
  }
}

/*! Geeft aan hoever de Zumo van het midden van de lijn zit. */
int LijnSensor::positie() {
  return lijnSensoren.readLine(lijnSensorWaarden);
}

/*! Geeft de afstand tot de lijn. */
int LijnSensor::error() {
  return lijnSensoren.readLine(lijnSensorWaarden) - 2000;
}

/*! Geeft een getal afhankelijk van de kleur van de lijn. */
int LijnSensor::kleur() {

}
