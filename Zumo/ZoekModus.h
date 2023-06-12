#pragma once
#include "Motoren.h"
#include "ObjectDetector.h"

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
