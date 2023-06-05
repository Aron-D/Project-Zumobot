#include "Motoren.h"
#include <Zumo32U4Encoders.h>

void Motoren::rechtdoor(int snelheid)
{
  motors.setSpeeds(snelheid, snelheid);
}

void Motoren::stop()
{
  motors.setSpeeds(0, 0);
}

void Motoren::rijRechts(int snelheid)
{
  motors.setSpeeds(0, snelheid);
}

void Motoren::rijLinks(int snelheid)
{
  motors.setSpeeds(snelheid, 0);
}

void Motoren::draaiLinks(int snelheid)
{
  motors.setSpeeds(-snelheid, snelheid);
}

void Motoren::draaiRechts(int snelheid)
{
  motors.setSpeeds(snelheid, -snelheid);
}

void Motoren::setSpeeds(int sL, int sR)
{
  motors.setSpeeds(sL, sR);
}

void Motoren::draai90links()
{
  const int draaiSlagen = 1200; 
  
  encoders.getCountsAndResetM1(); 

  while (encoders.getCountsM1() < draaiSlagen)
  {
    motors.setSpeeds(-200, 200);
  }

  motors.setSpeeds(0, 0); 
}

void Motoren::draai90rechts()
{
  const int draaiSlagen = 1200;
  
  encoders.getCountsAndResetM2();

  while (encoders.getCountsM2() < draaiSlagen)
  {
    motors.setSpeeds(200, -200);
  }

  motors.setSpeeds(0, 0); 
}
