#include "LijnVolgen.h"
// #include "Gyro.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;
Gyro Gyro;

void setup() 
{
  // Gebruik voor seriële communicatie: Serial.begin(9600);
  // Wire.begin();
  delay(1000);
  Gyro.init();
  lijnVolgen.init();
}

void loop() 
{
  // if (lijnVolgen.volgendeBocht == "")
  // {
  //   lijnVolgen.bocht_registratie();
  // }
  Gyro.ReturnAngle();
  lijnVolgen.stop_registratie();
  lijnVolgen.standaardModus();
}
