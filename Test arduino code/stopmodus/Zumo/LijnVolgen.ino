#include "LijnVolgen.h"


LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(200), volgendeBocht("") {}

void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

void LijnVolgen::stop_registratie() 
{
  motoren.rechtdoor(200);

  if (lijnSensor.lees_kleur(0) == "grijs" && lijnSensor.lees_kleur(4) == "grijs")
  {
    motoren.stop();
    delay(5000);
    Serial.println("poep");
  }
  else
  {
    Serial.println("niks te zien");
  }
}

void LijnVolgen::bocht_registratie()
{
//   int grijsCounterLinks = 0;
//   int grijsCounterRechts = 0;
//   while (lijnSensor.lees_sensor(0) > 200 && lijnSensor.lees_sensor(0) < 800)
  // {
//     grijsCounterLinks += 1;
//  }
//   if (grijsCounterLinks > 6)
//   {
//     volgendeBocht = "links";
  // }
//   while (lijnSensor.lees_sensor(4) > 200 && lijnSensor.lees_sensor(4) < 800)
//   {
//     grijsCounterRechts += 1;
//   }
//   if (grijsCounterRechts > 6)
//   {
//     volgendeBocht = "rechts";
//   }
}

void LijnVolgen::standaardModus()
{
//   Serial.println(volgendeBocht);
//   if (lijnSensor.lees_sensor(0) > 1100 || lijnSensor.lees_sensor(4) > 1100)
//   {
//     if (volgendeBocht == "links")
//     {
//       motoren.draai90links();
//       volgendeBocht = "";
//    }
//     else if (volgendeBocht == "rechts")
//     {
//       motoren.draai90rechts();
//       volgendeBocht = "";
//     }
//   }
//   error = lijnSensor.error();
//   int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
//   lastError = error;

//   int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
//   int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

//   snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
//   snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

//   motoren.setSpeeds(snelheidLinks, snelheidRechts);
}
