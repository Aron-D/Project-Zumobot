#include <Zumo32U4.h>
#include <Wire.h>
#include "LijnVolgen.h"

LijnVolgen lijnvolgen;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  lijnvolgen.init();
}

void loop() 
{
lijnvolgen.start();
lijnvolgen.kiesBocht();
}
