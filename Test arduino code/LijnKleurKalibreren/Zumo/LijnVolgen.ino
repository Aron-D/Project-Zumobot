#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(200), volgendeBocht("") {}

void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

 void LijnVolgen::bocht_registratie()
{
  // int grijsCounterLinks = 0;
  // int grijsCounterRechts = 0;
  if (lijnSensor.lees_sensor(0) > 200 && lijnSensor.lees_sensor(0) < 800)
  {
    grijsTellerLinks += 1;
  }
  else if (grijsTellerLinks > 4)
  {
    volgendeBocht = "links";
    grijsTellerLinks = 0;
    grijsTellerRechts = 0;
  }
  if (lijnSensor.lees_sensor(4) > 200 && lijnSensor.lees_sensor(4) < 800)
  {
    grijsTellerRechts += 1;
  }
  else if (grijsTellerRechts > 4)
  {
    volgendeBocht = "rechts";
    grijsTellerLinks = 0;
    grijsTellerRechts = 0;
  }
} 
/*
void LijnVolgen::bocht_registratie()
{
  if (volgendeBocht == "")
  {
    if(lijnSensor.lees_kleur(0) == "grijs") { grijsTellerLinks++; Serial.println("fortnite"); }
    else if(lijnSensor.lees_kleur(4) == "grijs") { grijsTellerRechts++; Serial.println("aefasefad"); }
    else { grijsTellerLinks = 0; grijsTellerRechts = 0; }

    if (grijsTellerLinks > 5)
    {
      volgendeBocht = "links";
      Serial.println(volgendeBocht);
      
      delay(1000);
    }
    else if (grijsTellerRechts > 5)
    {
      volgendeBocht = "rechts";
      Serial.println(volgendeBocht);
      
      delay(1000);
    }
  }
}
*/
void LijnVolgen::standaardModus()
{
  error = lijnSensor.error();
  
  int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
  lastError = error;

  int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
  int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

  snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
  snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

  motoren.setSpeeds(snelheidLinks, snelheidRechts);

  if (volgendeBocht != "")
  {
    if ((lijnSensor.lees_sensor(0) > 1500) || (lijnSensor.lees_sensor(4) > 1500))
    {
      if (volgendeBocht == "links")
      {
        motoren.draai90links();
        volgendeBocht = "";
        grijsTellerLinks = 0;
        grijsTellerRechts = 0;
      }
      else if (volgendeBocht == "rechts")
      {
        motoren.draai90rechts();
        volgendeBocht = "";
        grijsTellerLinks = 0;
        grijsTellerRechts = 0;
      }
    }
  }

}
