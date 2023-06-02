#include "Motoren.h"

void Motoren::rechtdoor(int snelheid)
{
  motors.setSpeeds(snelheid,snelheid);
}

void Motoren::stop()
{
  motors.setSpeeds(0,0);
}

void Motoren::rijRechts(int snelheid)
{
  motors.setSpeeds(snelheid, 0);
}

void Motoren::rijLinks(int snelheid)
{
  motors.setSpeeds(0, snelheid);
}

void Motoren::draaiLinks(int snelheid)
{
  motors.setSpeeds(-snelheid, snelheid);
}

void Motoren::draaiRechts(int snelheid)
{
  motors.setSpeeds(snelheid, -snelheid);
}

void Motoren::setSpeeds(int snelheidLinks, int snelheidRechts)
{
  motors.setSpeeds(snelheidLinks, snelheidRechts);
}
