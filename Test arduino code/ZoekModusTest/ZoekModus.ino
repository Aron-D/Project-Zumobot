#include "ZoekModus.h"

ZoekModus::ZoekModus()
{
  //scan diepte is een nummer van 1-6, 
  //hoe kleiner het nummer, hoe verder hij kan zien 
  detector.setScanDiepte(5);

  blokje_verwijderd = false;
}

void ZoekModus::zoekBlokje()
{
  motor.draaiLinks(100);

  detector.scan();
  if(detector.objectRichting() == Richting::Midden)
  {
    //rij vooruitvoor 5 seconden
    motor.rechtdoor(400);
    delay(5000);
    motor.stop();
    blokje_verwijderd = true;
    return;
  }

  blokje_verwijderd = false;
}

bool ZoekModus::blokjeVerwijderd()
{
  return blokje_verwijderd;
}