#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(300), volgendeBocht("") {}

LijnVolgen::LijnVolgen(LijnSensor& ls, Motoren& m) : lastError(0), error(0), maxSpeed(300), volgendeBocht(""), lijnSensor(ls), motoren(m) {}

void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

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
      }
      else if (lijnSensor.lees_kleur(4) == "grijs"/* && lijnSensor.lees_kleur(3) == "grijs"*/)
      {
        volgendeBocht = "rechts";
      }
      
      Serial.println(volgendeBocht);
    }
  }
}

void LijnVolgen::standaardModus()
{
  // if (lijnSensor.lees_kleur(0) == "grijs" && lijnSensor.lees_kleur(4) == "grijs")
  // {
  //   motoren.stop();
  //   delay(2000);
  //   motoren.rechtdoor(100);
  // }
  error = lijnSensor.error();
  
  int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
  lastError = error;

  int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
  int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

  snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
  snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

  motoren.setSpeeds(snelheidLinks, snelheidRechts);

  /*if ((lijnSensor.lees_sensor(0) > 1500) || (lijnSensor.lees_sensor(4) > 1500))
  {
    if (volgendeBocht == "links")
    {
      motoren.draai90links();
      volgendeBocht = "";
    }
    else if (volgendeBocht == "rechts")
    {
      motoren.draai90rechts();
      volgendeBocht = "";
    }
  }*/
}
