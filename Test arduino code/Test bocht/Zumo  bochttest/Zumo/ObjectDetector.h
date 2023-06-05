#pragma once
#include <Zumo32U4ProximitySensors.h>

enum class Richting
{
  Links,
  Rechts,
  Midden,
  Geen
};

class ObjectDetector
{
private:
  Zumo32U4ProximitySensors m_proximitySensor;
  int m_readingsLeftLed;
  int m_readingsRightLed;

public:
  ObjectDetector();

  void scan();

  bool objectGedetecteerd() const;
  Richting objectRichting() const;
};
