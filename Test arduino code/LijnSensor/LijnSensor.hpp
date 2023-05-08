/*!
  @mainpage LijnSensor Zumo
  
  LijnSensor is een klasse die de lijnsensoren op een Zumo robot kan initialiseren, kalibreren en uitlezen.
*/

/*!
  @file LijnSensor.hpp
  @date 26 Apr 2023
  @author Ruben van Eijken

  Een klasse die de lijnsensoren op een Zumo robot kan initialiseren, kalibreren en uitlezen.
  De Zumo robot heeft vijf lijnsensoren die lichtwaarden meten waardoor een donkere lijn op een lichte achtergrond gedetecteerd kan worden.

  modified 26 Apr 2023
  by Ruben van Eijken
  modified 2 May 2023
  by Ruben van Eijken
  modified 4 May 2023
  by Ruben van Eijken
*/

#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4LineSensors.h>

/*! De klasse LijnSensor heeft als functie het initialiseren, kalibreren en uitlezen van de lijnsensoren. */
class LijnSensor {
  public:
    LijnSensor();
    void sensoren_initialiseren();
    void sensoren_kalibreren();
    int lijn_positie();
    int lijn_error();

  private:
    Zumo32U4LineSensors lijnSensoren;
    uint16_t lijnSensorWaarden[5];
};

/*! Constructor die nu niets doet. */
LijnSensor::LijnSensor() {

}

/*! Vertelt de Zumo dat alle vijf de lijnsensoren gebruikt moeten worden. */
void LijnSensor::sensoren_initialiseren() {
  lijnSensoren.initFiveSensors();
}

/*! Kalibratie door metingen uit te lezen van de lijnsensoren en vervolgens te bepalen wat "licht" en "donker" is. */
void LijnSensor::sensoren_kalibreren() {
  for(uint16_t i = 0; i < 120; i++)
  {
    lijnSensoren.calibrate();
  }
}

/*! Geeft aan waar de lijn zit. */
int LijnSensor::lijn_positie() {
  return lijnSensoren.readLine(lijnSensorWaarden);
}

/*! Geeft de afstand tot de lijn. */
int LijnSensor::lijn_error() {
  return lijnSensoren.readLine(lijnSensorWaarden) - 2000;
}
#endif
