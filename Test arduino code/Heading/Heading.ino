/*!
  @file Heading.ino
  @date 5 May 2023
  @author Aron Dosti

*/

//uitroep h file voor class Kompas
#include "Kompas.h"

// uitroep constructor als object k
Kompas k;

//constructor init wordt uitgeroepen. hier komt de configuratie voor de void setup
void setup() {
k.init();
}

//constructor graden wordt uitgeroepen. hier komt de uitvoer voor de void loop. in seriele monitor wordt de data getoont
void loop() {
  Serial.println(k.graden());
  
  //om de data langzamer te tonen. dit kan je uit zetten, maar de data zal vlug op het seriele monitor getoont worden 
  delay(100);
}