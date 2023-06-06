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
  const int draaiSlagen =  1900; 
  
  encoders.getCountsAndResetRight();

  while (encoders.getCountsRight() < draaiSlagen)
  {
    motors.setSpeeds(0, 200);
    //Serial.println(encoders.getCountsRight());
  }

  motors.setSpeeds(0, 0); 
}

void Motoren::draai90rechts()
{
  const int draaiSlagen =  1900; 
  
  encoders.getCountsAndResetLeft();

  while (encoders.getCountsLeft() < draaiSlagen)
  {
    motors.setSpeeds(200, 0);
    //Serial.println(encoders.getCountsLeft());
  }

  motors.setSpeeds(0, 0); 
}

void Motoren::stap()
{
  const int targetCount = 1440;  // Aantal pulsen per volledige stap (360 graden)
  int leftCount = encoders.getCountsLeft();
  int rightCount = encoders.getCountsRight();

  // Stop de motoren
  stop();

  // Wacht totdat de motoren volledig tot stilstand zijn gekomen
  while (encoders.getCountsLeft() != leftCount || encoders.getCountsRight() != rightCount) {
    leftCount = encoders.getCountsLeft();
    rightCount = encoders.getCountsRight();
    delay(1);
  }

  // Draai de motoren één stap
  setSpeeds(200, 200);
  while (encoders.getCountsLeft() - leftCount < targetCount && encoders.getCountsRight() - rightCount < targetCount) {
    delay(1);
  }

  // Stop de motoren na één stap
  stop();
}
