#include "LijnVolgen.h"
#include "Motoren.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;;

void setup() 
{
  lijnVolgen.init();
}

void loop() 
{
  lijnVolgen.bocht_registratie();
  lijnVolgen.standaardModus();
}
