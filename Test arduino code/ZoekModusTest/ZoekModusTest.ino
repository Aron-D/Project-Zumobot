#include "ZoekModus.h"

ZoekModus zoekmodus;
bool running = true;

void setup() 
{
  // put your setup code here, to run once:
  //...
}

void loop() 
{
  while(running)
  {
    //zoek het blokje en rij er naartoe
    zoekmodus.zoekBlokje();

    //als het blokje uit de cirkel is stopt het programma
    if(zoekmodus.blokjeVerwijderd())
    {
      running = false;
    }
  }
}
