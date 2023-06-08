#ifndef LIJNVOLGEN_H
#define LIJNVOLGEN_H

#include "Motoren.h"
#include "LijnSensor.h"
// #include "gyro.h"


class LijnVolgen
{
public:
  LijnVolgen();
  void init();
  void standaardModus();
  void bocht_registratie();
  void stop_registratie();
  String volgendeBocht;

private:
  Motoren motoren;
  LijnSensor lijnSensor;
  // Gyro gyro;
  int16_t lastError;
  int16_t error;
  int16_t maxSpeed;
};

#endif
