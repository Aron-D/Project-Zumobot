#include "Motoren.h"

/* zet beide motoren op precies dezelfde snelheid, waardoor de Zumo vooruit rijdt */
void Motoren::rechtdoor(int snelheid)
{
  motors.setSpeeds(snelheid, snelheid);
}
/* zet beide motoren op 0 snelheid, hierdoor stopt de Zumo */
void Motoren::stop()
{
  motors.setSpeeds(0, 0);
}

/* zet alleen de snelheid van de rechtermotor, hierdoor draait de zumo naar rechts */
void Motoren::rijRechts(int snelheid)
{
  motors.setSpeeds(0, snelheid);
}

/* zet alleen de snelheid van de linkermotor, hierdoor draait de zumo naar links */
void Motoren::rijLinks(int snelheid)
{
  motors.setSpeeds(snelheid, 0);
}

/* zet de linkermoter op de negatieve snelheid van de rechtermotor, hierdoor draait de Zumo op zijn plek naar links */
void Motoren::draaiLinks(int snelheid)
{
  motors.setSpeeds(-snelheid, snelheid);
}

/* zet de rechtermoter op de negatieve snelheid van de linkermotor, hierdoor draait de Zumo op zijn plek naar rechts */
void Motoren::draaiRechts(int snelheid)
{
  motors.setSpeeds(snelheid, -snelheid);
}

/* zet de linker en rechtermotor precies op de meegegeven waardes */
void Motoren::setSpeeds(int sL, int sR)
{
  motors.setSpeeds(sL, sR);
}

/* zet een vast aantal draaislagen en reset/leest dan de encoders in, zolang het aantal die de encoders meten onder het aantal draaislagen zal de Zumo naar links blijven draaien. deze functie is zo ingestelt dat de Zumo precies een bocht van 90 graden maakt */
void Motoren::draai90links()
{
  const int draaiSlagen =  1900; 
  
  encoders.getCountsAndResetRight();

  while (encoders.getCountsRight() < draaiSlagen)
  {
    motors.setSpeeds(0, 200);
  }

  motors.setSpeeds(0, 0); 
}

/* zet een vast aantal draaislagen en reset/leest dan de encoders in, zolang het aantal die de encoders meten onder het aantal draaislagen zal de Zumo naar rechts blijven draaien. deze functie is zo ingestelt dat de Zumo precies een bocht van 90 graden maakt */

void Motoren::draai90rechts()
{
  const int draaiSlagen =  1900; 
  
  encoders.getCountsAndResetLeft();

  while (encoders.getCountsLeft() < draaiSlagen)
  {
    motors.setSpeeds(200, 0);
  }

  motors.setSpeeds(0, 0); 
}
