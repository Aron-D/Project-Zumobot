#pragma once
#include <Zumo32U4ProximitySensors.h>

/*! Dit is een lijst met de richtingen waarin een object gedetecteerd kan worden. */
enum class Richting
{
  Links,
  Rechts,
  Midden,
  Geen
};

/*!
Deze klasse kan gebruikt worden om te kijken of de Zumo objecten ziet, en waar deze objecten zich bevinden.
Om objecten te kunnen zien maakt deze klasse gebruik van de proximity sensoren op de Zumo.
*/
class ObjectDetector
{
private:
  Zumo32U4ProximitySensors m_proximitySensor;
  int m_scanDiepte;
  int m_readingsLeftLed;
  int m_readingsRightLed;

public:
  ObjectDetector();

  void scan();

  void setScanDiepte(int d);
  bool objectGedetecteerd() const;
  Richting objectRichting() const;
};
