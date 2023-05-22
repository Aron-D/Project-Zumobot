/*!
  @mainpage LijnSensor Zumo
  
  LijnSensor is een klasse die de lijnsensoren op een Zumo robot kan initialiseren, calibreren en uitlezen.
*/

/*!
  @file LijnSensor.hpp
  @date 26 Apr 2023
  @author Ruben van Eijken

  Een klasse die de lijnsensoren op een Zumo robot kan initialiseren, calibreren en uitlezen.
  De Zumo robot heeft vijf lijnsensoren die lichtwaarden meten waardoor een donkere lijn op een lichte achtergrond gedetecteerd kan worden.

  modified 26 Apr 2023
  by Ruben van Eijken
  modified 2 May 2023
  by Ruben van Eijken
*/

#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include "Motoren.h"
#include <Zumo32U4LineSensors.h>

/*! De klasse LijnSensor heeft als functie het initialiseren, calibreren en uitlezen van de lijnsensoren. */
class LijnSensor {
  public:
    void sensoren_initialiseren();
    void sensoren_kalibreren(Motoren& m);
    int lijn_positie();
    int lijn_error();

  private:
    Zumo32U4LineSensors lijnSensoren;
    uint16_t lijnSensorWaarden[5];
};

#endif
