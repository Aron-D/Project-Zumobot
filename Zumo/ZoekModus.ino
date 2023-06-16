#include "ZoekModus.h"

/*! Initialiseer de zoekModus */
ZoekModus::ZoekModus()
{
  // Scan diepte is een nummer van 1-6, hoe kleiner het nummer, hoe verder hij kan zien
  detector.setScanDiepte(3);

  blokje_verwijderd = false;
}

/*!
Dit moet continu uitgevoerd worden als de Zumo het blokje moet zoeken.
Deze functie kijkt waar het blokje is ten opzichte van de Zumo, en rijd vervolgens die kant op.
*/
void ZoekModus::zoekBlokje()
{

  detector.scan(); // Scant of er een object voor de zumo staat
  Richting richting = detector.objectRichting(); // Kijkt of het object links, rechts of voor de sensor staat

  // In deze case wordt gekeken wat de richting is die detector.objectRichting returned en past de rijrichting van de zumo daarop aan, als er geen object is gedetecteerd zal de Zumo rondjes gaan draaien
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
  // Stopt de motor na een 20 sec, zet blokje_verwijdert op true
  if((millis() - start_tijd) > 20000)
  {
    motor.stop();
    blokje_verwijderd = true;
  }
}

/*! Return of het blokje is verwijderd of niet */
bool ZoekModus::blokjeVerwijderd()
{
  return blokje_verwijderd;
}

/*!
Dit moet worden uitgevoerd voordat de Zumo het blokje gaat zoeken.
Deze functie start de timer van 20 sec, en rijd naar het midden van de cirkel 
*/
void ZoekModus::startZoekMode()
{
  start_tijd = millis();

  motor.rechtdoor(300);
  delay(1000);
  motor.stop();
}
