#include "LijnVolgen.h"
#include "Motoren.h"
// Gebruik voor seriële communicatie: #include <Wire.h>

LijnVolgen lijnVolgen;;
Motoren motoren;

void setup() 
{
  // Gebruik voor seriële communicatie: Serial.begin(9600);
  // Wire.begin();
  delay(1000);
  //ijnVolgen.init();
     motoren.draai90rechts();
     delay(3000);
     motoren.draai90links();
    motoren.stap();
}

void loop() 
{
 /* if (lijnVolgen.volgendeBocht == "")
  {
    lijnVolgen.bocht_registratie();
  }
  lijnVolgen.standaardModus();
  */

  
}
