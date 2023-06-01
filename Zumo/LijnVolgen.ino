#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(300) {}

void LijnVolgen::init()
{
  lijnsensor.initialiseren();
  lijnsensor.kalibreren(motoren);
}

void LijnVolgen::start()
{
  error = lijnsensor.error();
  int16_t snelheidsVerschil = error / 4 + 6 * (error - lastError);
  lastError = error;

  int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
  int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

  snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
  snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

  motoren.setSpeeds(snelheidLinks, snelheidRechts);
}
