#include "ZoekModus.h"

ZoekModus::ZoekModus()
{
  //scan diepte is een nummer van 1-6, 
  //hoe kleiner het nummer, hoe verder hij kan zien 
  detector.setScanDiepte(3);

  blokje_verwijderd = false;
}

void ZoekModus::zoekBlokje()
{
  detector.scan();
  Richting richting = detector.objectRichting();

  switch (richting) 
  {
  case Richting::Midden:
    motor.rechtdoor(400);
    break;
  case Richting::Links:
    motor.rijLinks(400);
    delay(50);
    break;
  case Richting::Rechts:
    motor.rijRechts(400);
    delay(50);
    break;
  case Richting::Geen:
    motor.draaiLinks(150);
    break;
  }

  if((millis() - start_tijd) > 20000)
  {
    motor.stop();
    blokje_verwijderd = true;
  }
}

bool ZoekModus::blokjeVerwijderd()
{
  return blokje_verwijderd;
}

void ZoekModus::startZoekMode()
{
  start_tijd = millis();

  motor.rechtdoor(300);
  delay(1000);
  motor.stop();
}