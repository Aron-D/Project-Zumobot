#include "LijnVolgen.h"
#include "LijnSensor.h"
#include "Motoren.h"

LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(150), volgendeBocht("") {}

void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

/* void LijnVolgen::bocht_registratie()
{
  int grijsCounterLinks = 0;
  int grijsCounterRechts = 0;
  while (lijnSensor.lees_sensor(0) > 200 && lijnSensor.lees_sensor(0) < 800)
  {
    grijsCounterLinks += 1;
  }
  if (grijsCounterLinks > 6)
  {
    volgendeBocht = "links";
  }
  while (lijnSensor.lees_sensor(4) > 200 && lijnSensor.lees_sensor(4) < 800)
  {
    grijsCounterRechts += 1;
  }
  if (grijsCounterRechts > 6)
  {
    volgendeBocht = "rechts";
  }
} */

void LijnVolgen::bocht_registratie()
{
  if (volgendeBocht == "")
  {
    if ((lijnSensor.lees_kleur(0) == "grijs" /*&& lijnSensor.lees_kleur(1) == "grijs"*/) || (lijnSensor.lees_kleur(4) == "grijs" /*&& lijnSensor.lees_kleur(3) == "grijs"*/))
    {
      //motoren.stap();
      //delay(500);

      if (lijnSensor.lees_kleur(0) == "grijs"/* && lijnSensor.lees_kleur(1) == "grijs"*/)
      {
        volgendeBocht = "links";
        motoren.draai90links();
      }
      else if (lijnSensor.lees_kleur(4) == "grijs"/* && lijnSensor.lees_kleur(3) == "grijs"*/)
      {
        volgendeBocht = "rechts";
        motoren.draai90rechts();
      }
      
      Serial.println(volgendeBocht);
    }
  }
}

void LijnVolgen::standaardModus()
{
  
  error = lijnSensor.error();

  if (lijnSensor.error() > -2000 && lijnSensor.error() < 2000) {
  int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
  lastError = error;

  int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
  int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

  snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
  snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

  motoren.setSpeeds(snelheidLinks, snelheidRechts);

  // if ((lijnSensor.lees_sensor(0) > 1500) || (lijnSensor.lees_sensor(4) > 1500))
  // {
  //   if (volgendeBocht == "links")
  //   {
  //     motoren.draai90links();
  //     volgendeBocht = "";
  //   }
  //   else if (volgendeBocht == "rechts")
  //   {
  //     motoren.draai90rechts();
  //     volgendeBocht = "";
  //   }
    
  
  }
  else {
    motoren.rechtdoor(300);
    

  }
}
