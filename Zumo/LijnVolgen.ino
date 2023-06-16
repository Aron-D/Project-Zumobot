#include "LijnVolgen.h"

/* constructor voor Lijnvolgen */
LijnVolgen::LijnVolgen() : lastError(0), error(0), maxSpeed(300), volgendeBocht("") {}

/* contructor voor Lijnvolgen */
LijnVolgen::LijnVolgen(LijnSensor& ls, Motoren& m) : lastError(0), error(0), maxSpeed(300), volgendeBocht(""), lijnSensor(ls), motoren(m) {}

/* Functie die alles dat nodig is om de sensors te calibreren aanroept */
void LijnVolgen::init()
{
  lijnSensor.initialiseren();
  lijnSensor.kalibreren(motoren);
}

/* checkt de buitenste 2 kleursensors voor de kleur grijs en slaat de richting waar hij grijs registreerd op in 'volgendebocht' */
void LijnVolgen::bocht_registratie()
{
  /* checkt de buitenste 2 sensors voor grijs en slaat de richting op in 'volgendebocht' */
  if (volgendeBocht == "")
  {
    if ((lijnSensor.lees_kleur(0) == "grijs") || (lijnSensor.lees_kleur(4) == "grijs" ))
    {
      
      if (lijnSensor.lees_kleur(0) == "grijs")
      {
        volgendeBocht = "links";
      }
      else if (lijnSensor.lees_kleur(4) == "grijs")
      {
        volgendeBocht = "rechts";
      }
      
      Serial.println(volgendeBocht);
    }
  }
}
/* Volgt een zwarte lijn door op basis van de error de motoren aan te sturen. */
void LijnVolgen::standaardModus()
{
  /* Wanneer alle sensoren 'wit' zien, oftewel een lage waarde, gaat de Zumo rechtvooruit. Is gemaakt voor stippellijnen. */
  if (lijnSensor.lees_sensor(0) < 300 && lijnSensor.lees_sensor(1) < 300 && lijnSensor.lees_sensor(2) < 300 && lijnSensor.lees_sensor(3) < 300 && lijnSensor.lees_sensor(4) < 300)
  {
    motoren.rechtdoor(200);
  }
  else
  {
    error = lijnSensor.error();
    
    /* De eerste term kijkt alleen naar de huidige error. De tweede term kijkt naar hoeveel de error verandert is ten opzichte van de laatste keer dat de functie is uitgevoerd.
    Op basis van deze termen wordt het snelheidsverschil tussen de motoren bepaald. */
    int16_t snelheidsVerschil = error / 1 + 4 * (error - lastError);
    lastError = error;

    /* Bepaalt de snelheden voor de linker en rechter motor. */
    int16_t snelheidLinks = maxSpeed + snelheidsVerschil;
    int16_t snelheidRechts = maxSpeed - snelheidsVerschil;

    /* Zorgt ervoor dat de minimale waarde en de maximale waarde beperkt zijn tot snelheden die de Zumo aan kan. */
    snelheidLinks = constrain(snelheidLinks, -maxSpeed, maxSpeed);
    snelheidRechts = constrain(snelheidRechts, -maxSpeed, maxSpeed);

    motoren.setSpeeds(snelheidLinks, snelheidRechts);
  }
}
