#include <Zumo32U4Motors.h>
#include <Zumo32U4Encoders.h>

#ifndef MOTOREN_H
#define MOTOREN_H

class Motoren
{
public:
  void rechtdoor(int snelheid);
  void stop();
  void rijLinks(int snelheid);
  void rijRechts(int snelheid);
  void draaiLinks(int snelheid);
  void draaiRechts(int snelheid);
  void setSpeeds(int, int);

private:
  Zumo32U4Motors motors;
};

#endif
