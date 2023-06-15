/*!
  @file Zumo.ino
  @author Ruben van Eijken, Luka Grouwstra, 

  The main class for the Zumo, all main functions are called for here
  The switch from StandaardModus to zoekModus upon detecting the color brown is also implemented here
*/


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
  /*runs right before the main loop of the program. Also initializes the sensors to calibrate them */
  delay(1000);
  lijnVolgen.init();
}

void loop()
{
  while (standaardActief) /*check to see if standaardModus is enabled */
  {
    lijnVolgen.standaardModus(); /* activate the standaardModus */

    /*checks if the sensors see the color brown, activates zoekModus if true */
    if (lijnSensoren.lees_kleur(0) == "bruin") 
    {
      zoekenActief = true;
      standaardActief = false;

      motoren.stop(); 
      delay(2000); 

      zoekModus.startZoekMode(); /* activates zoekMode */
    }
  }

  while (zoekenActief) /* checks to see if zoekMode is enabled */
  {
    zoekModus.zoekBlokje(); /* activates zoekMode */

    /* Deactivated both modes the moment the block is removed, ending the program */
    if (zoekModus.blokjeVerwijderd()) 
    {
      zoekenActief = false;
      standaardActief = false;
    }
  }
}
