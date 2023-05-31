#include "ZoekModus.h"

ZoekModus::ZoekModus()
{
  //scan diepte is een nummer van 1-6, 
  //hoe kleiner het nummer, hoe verder hij kan zien 
  detector.setScanDiepte(5);
}

void ZoekModus::zoekBlokje()
{
  delay(50);

  motor.draaiLinks(100);

  detector.scan();
  if(detector.objectRichting() == Richting::Midden)
  {
    while(true) { motor.rechtdoor(400); }
  }
}
