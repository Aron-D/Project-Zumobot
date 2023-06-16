/*!
  @mainpage Groep 1.3

  Code voor de Zumo robot voor het project "Systems Engineering".
  Met deze code kan de Zumo robot een parkoers afgelegen waarbij een zwarte lijn gevolgd wordt.
  Ook heeft de Zumo wat extra functionaliteiten. Er kan een blokje binnen een cirkel worden gevonden.
  De Zumo kan een stippellijn volgen en er kunnen verschillende kleuren herkend worden.
*/

/*!
  @file Zumo.ino
  @author Ruben van Eijken, Luka Grouwstra

  The main class for the Zumo, all main functions are called for here.
  The switch from StandaardModus to zoekModus upon detecting the color brown is also implemented here.
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

/*! Runs right before the main loop of the program. Also initializes the sensors to calibrate them */
void setup()
{
  delay(1000);
  lijnVolgen.init();
}

/*! The loop routine runs over and over */
void loop()
{
  while (standaardActief) // Check to see if standaardModus is enabled
  {
    lijnVolgen.standaardModus(); // Activate the standaardModus

    // Checks if the sensors see the color brown, activates zoekModus if true
    if (lijnSensoren.lees_kleur(0) == "bruin") 
    {
      zoekenActief = true;
      standaardActief = false;

      motoren.stop(); 
      delay(2000); 

      zoekModus.startZoekMode(); // Activates zoekMode
    }
  }

  while (zoekenActief) // Checks to see if zoekMode is enabled
  {
    zoekModus.zoekBlokje(); // Activates zoekMode

    // Deactivated both modes the moment the block is removed, ending the program
    if (zoekModus.blokjeVerwijderd()) 
    {
      zoekenActief = false;
      standaardActief = false;
    }
  }
}
