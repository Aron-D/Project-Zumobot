#include "LijnVolgen.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;

void setup() 
{
  // Gebruik voor seriële communicatie: Serial.begin(9600);
  // Wire.begin();
  delay(1000);
  lijnVolgen.init();
}

void loop() 
{
  lijnVolgen.standaardModus();
}
