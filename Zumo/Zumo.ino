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

void setup()
{
  delay(1000);
  lijnVolgen.init();
}

void loop() 
{
  while (standaardActief)
  {
    lijnVolgen.standaardModus();

    if (lijnSensoren.lees_kleur(0) == "bruin")
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
