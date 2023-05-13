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
  motors.setSpeeds(-snelheid,snelheid);
}

void Motoren::rijLinks(int snelheid)
{
  motors.setSpeeds(snelheid,-snelheid);
}