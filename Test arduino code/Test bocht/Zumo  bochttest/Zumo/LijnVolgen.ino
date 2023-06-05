#include "LijnVolgen.h"
#include "Motoren.h"


LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(300) {}

void LijnVolgen::init()
{
  lijnsensor.initialiseren();
  lijnsensor.kalibreren(motoren);
}

void LijnVolgen::start()
{
  //kijk of er een bocht gemaakt moet worden
  if (lijnsensor.sensorWaarden[0] > 900 || lijnsensor.sensorWaarden[4] > 900) 
  {
    //kijk of we naar links of rechts moeten
    if (volgendebocht == "links") 
    {
      motoren.draai90links();
      volgendebocht = "niks";
    }
    if (volgendebocht == "rechts")
    {
      motoren.draai90rechts();
      volgendebocht = "niks";
    }
  }
  else 
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
}  

void LijnVolgen::kiesBocht() {
  if (lijnsensor.sensorWaarden[0] < 900 && lijnsensor.sensorWaarden[0] > 220) 
  {
    volgendebocht = "links";
    Serial.println(volgendebocht);
  }
  else if (lijnsensor.sensorWaarden[4] < 1000 && lijnsensor.sensorWaarden[4] > 200) 
  {
    volgendebocht = "rechts";
    Serial.println(volgendebocht);
  } 
  else
  {

  }
}

