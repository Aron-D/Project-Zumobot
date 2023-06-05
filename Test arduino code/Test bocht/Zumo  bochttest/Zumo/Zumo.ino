#include <Zumo32U4.h>
#include <Wire.h>
#include "LijnVolgen.h"
#include "Motoren.h"

LijnVolgen lijnvolgen;
Motoren motoren;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  delay(1000);
  // lijnvolgen.init();
  delay(1000);
  motoren.draai90links();
}

void loop() 
{

}
