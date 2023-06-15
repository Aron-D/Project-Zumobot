#pragma once
#include "Motoren.h"
#include "ObjectDetector.h"

/* 
Als deze modus wordt geactiveerd zal de Zumo zoeken naar het blokje, en deze uit de cirkel dieuwen.
*/
class ZoekModus
{
private:
  Motoren motor;
  ObjectDetector detector;

  unsigned long start_tijd;
  bool blokje_verwijderd;

public:
  ZoekModus();
  void zoekBlokje();
  bool blokjeVerwijderd();
  void startZoekMode();
};
