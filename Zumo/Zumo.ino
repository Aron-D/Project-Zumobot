#include "LijnVolgen.h"
#include "ZoekModus.h"
#include "LijnSensor.h"
#include "Motoren.h"

LijnSensor lijnSensoren;
Motoren motoren;
LijnVolgen lijnVolgen(lijnSensoren, motoren);
ZoekModus zoekModus;
bool zoekenActief = false;
bool standaardActief = true;

// testing //
int draaiNegentigLinks = 2;
int draaiNegentigRechts = 2;

void setup()
{
  delay(1000);
  lijnVolgen.init();
}

void loop()
{
  while (standaardActief)
  {
    /*if (lijnSensoren.lees_sensor(0) > 1400 && draaiNegentigLinks != 0)
    {
      draaiNegentigLinks = draaiNegentigLinks - 1;
      motoren.draai90links();
    }
    if (lijnSensoren.lees_sensor(4) > 1400 && draaiNegentigRechts != 0)
    {
      draaiNegentigRechts = draaiNegentigRechts - 1;
      motoren.draai90rechts();
    }*/

    lijnVolgen.standaardModus();

    if (lijnSensoren.lees_kleur(0) == "testing") // vervang testing door bruin...
    {
      zoekenActief = true;
      standaardActief = false;

      motoren.stop(); // testing...
      delay(2000); // testing...

      zoekModus.startZoekMode();
    }
  }

  while (zoekenActief)
  {
    zoekModus.zoekBlokje();

    if (zoekModus.blokjeVerwijderd())
    {
      zoekenActief = false;
      standaardActief = false;
    }
  }
}
