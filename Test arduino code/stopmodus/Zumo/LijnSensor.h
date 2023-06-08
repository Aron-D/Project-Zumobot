/*!
  @mainpage LijnSensor Zumo

  Declaratie van de klasse "LijnSensor".
  LijnSensor is een klasse die de lijnsensoren op een Zumo robot kan initialiseren, calibreren en uitlezen.
*/

/*!
  @file LijnSensor.hpp
  @author Ruben van Eijken

  Een klasse die de lijnsensoren op een Zumo robot kan initialiseren, calibreren en uitlezen.
  De Zumo robot heeft vijf lijnsensoren die lichtwaarden meten waardoor een donkere lijn op een lichte achtergrond gedetecteerd kan worden.
*/

#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4LineSensors.h>
#include <Zumo32U4.h>

/*! De klasse LijnSensor heeft als functie het initialiseren, calibreren en uitlezen van de lijnsensoren. */
class LijnSensor
{
public:
  LijnSensor();
  void initialiseren();
  void kalibreren(Motoren& m);
  int error();
  int lees_sensor(int);
  String lees_kleur(int);

private:
  void kalibreer_kleuren(int& min, int& max, Motoren& m);

  Zumo32U4LineSensors lijnSensoren;
  uint16_t sensorWaarden[5];

  int zwartMinimumWaarde;
  int zwartMaximumWaarde;

  int grijsMinimumWaarde;
  int grijsMaximumWaarde;

  int groenMinimumWaarde;
  int groenMaximumWaarde;

  int bruinMinimumWaarde;
  int bruinMaximumWaarde;
};

#endif
