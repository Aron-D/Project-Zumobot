#include "WString.h"
#ifndef LIJNSENSOR_H
#define LIJNSENSOR_H

#include <Zumo32U4LineSensors.h>
#include <Zumo32U4.h>

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
