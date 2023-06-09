#include "LijnVolgen.h"
#include "Motoren.h"
#include "ZoekModus.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;
ZoekModus ZoekModus;

void setup() 
{
  delay(1000);
  lijnVolgen.init();
}

void loop() 
{
  lijnVolgen.bocht_registratie();
  lijnVolgen.standaardModus();
}
