#pragma once
#include "Motoren.h"
#include "ObjectDetector.h"

class ZoekModus
{
private:
  Motoren motor;
  ObjectDetector detector;

public:
  ZoekModus();
  void zoekBlokje();
};