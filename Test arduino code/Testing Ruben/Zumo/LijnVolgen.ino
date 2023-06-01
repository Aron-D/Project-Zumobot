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
  if (lijnsensor.lees_sensor(0) > 800)
  {
    motoren.rijLinks(300);
    delay(400);
  }
  else if (lijnsensor.lees_sensor(4) > 800)
  {
    motoren.rijRechts(300);
    delay(400);
  }
  else
  {
    int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
    lastError = error;

    int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
    int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

    snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
    snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

    motoren.setSpeeds(snelheidLinks, snelheidRechts);
  }
}
