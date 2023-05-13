#pragma once
#include <Zumo32U4Motors.h>

class Motoren
{
public:
  void rechtdoor(int snelheid);
  void stop();
  void rijLinks(int snelheid);
  void rijRechts(int snelheid);

private:
  Zumo32U4Motors motors;
};