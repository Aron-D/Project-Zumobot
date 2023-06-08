#include "LijnVolgen.h"
#include "Motoren.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;

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
