#include "ZoekModus.h"

ZoekModus::ZoekModus()
{
  /*scan diepte is een nummer van 1-6, 
  hoe kleiner het nummer, hoe verder hij kan zien */
  detector.setScanDiepte(3);

  blokje_verwijderd = false;
}

/* Modus die met de objectsensor kijkt of er een object voor de zumo staat. Veranderd de richting van rijden aan de hand van "error" tussen de objectsensor en het object */
void ZoekModus::zoekBlokje()
{

  detector.scan(); /* scant of er een object voor de zumo staat */
  Richting richting = detector.objectRichting(); /* kijkt of het object links, rechts of voor de sensor staat */


  /* in deze case wordt gekeken wat de richting is die detector.objectRichting returned en past de rijrichting van de zumo daarop aan */
  switch (richting) 
  {
  case Richting::Midden:
    motor.rechtdoor(400);
    break;
  case Richting::Links:
    motor.rijRechts(400);
    delay(50);
    break;
  case Richting::Rechts:
    motor.rijLinks(400);
    delay(50);
    break;
  case Richting::Geen:
    motor.draaiLinks(150);
    break;
  }
  /* stopt de motor na een bepaalde tijd en eindigd de zoekmodus */
  if((millis() - start_tijd) > 20000)
  {
    motor.stop();
    blokje_verwijderd = true;
  }
}
/* returned of het blokje is verwijderd of niet */
bool ZoekModus::blokjeVerwijderd()
{
  return blokje_verwijderd;
}
/* start de zoekmodus */
void ZoekModus::startZoekMode()
{
  start_tijd = millis();

  motor.rechtdoor(300);
  delay(1000);
  motor.stop();
}
