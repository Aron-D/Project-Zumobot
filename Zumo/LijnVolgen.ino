#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(300) {}

void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

void LijnVolgen::standaardModus()
{
  error = lijnSensor.error();
  if (lijnSensor.lees_sensor(0) > 800)
  {
    motoren.rijLinks(300);
    delay(400);
  }
  else if (lijnSensor.lees_sensor(4) > 800)
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
