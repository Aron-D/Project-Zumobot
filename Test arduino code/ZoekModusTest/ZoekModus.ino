#include "ZoekModus.h"

ZoekModus::ZoekModus()
{
  //scan diepte is een nummer van 1-6, 
  //hoe kleiner het nummer, hoe verder hij kan zien 
  detector.setScanDiepte(5);
}

bool ZoekModus::zoekBlokje()
{
  detector.scan();
  Richting objectRichting = detector.objectRichting();
  
  switch(objectRichting)
  {
  case Richting::Geen:
    motor.draaiLinks(100);
    break;
  
  case Richting::Midden:
    motor.rechtdoor(100);
    break;

  case Richting::Links:
    motor.rijLinks(100);
    break;

  case Richting::Rechts:
    motor.rijRechts(100);
    break;

  default:
    break;
  }
}