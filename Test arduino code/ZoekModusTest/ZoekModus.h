#pragma once
#include "Motoren.h"
#include "ObjectDetector.h"

class ZoekModus
{
private:
  Motoren motor;
  ObjectDetector detector;

  bool blokje_verwijderd;

public:
  ZoekModus();
  void zoekBlokje();
  bool blokjeVerwijderd();
};