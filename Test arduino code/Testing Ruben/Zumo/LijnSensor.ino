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

LijnSensor::LijnSensor() {}

/*! Vertelt de Zumo dat alle vijf de lijnsensoren gebruikt moeten worden. */
void LijnSensor::initialiseren()
{
  lijnSensoren.initFiveSensors();
}

/*! Calibratie door metingen uit te lezen van de lijnsensoren en vervolgens te bepalen wat "licht" en "donker" is. */
void LijnSensor::kalibreren(Motoren& m)
{
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      m.draaiLinks(200);
    }
    else
    {
      m.draaiRechts(200);
    }
    lijnSensoren.calibrate();
  }
  m.stop();
}

/*! Geeft de afstand tot de lijn. */
int LijnSensor::error()
{
  return lijnSensoren.readLine(sensorWaarden) - 2000;
}

int LijnSensor::lees_sensor(int i)
{
  return sensorWaarden[i];
}
