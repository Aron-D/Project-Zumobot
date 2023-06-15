#include "ObjectDetector.h"

/* constructor voor Objectdetector */
ObjectDetector::ObjectDetector()
{
  m_proximitySensor.initThreeSensors();
  m_scanDiepte = 5;
}

/* zet de scandiepte naar het meegegeven getal */
void ObjectDetector::setScanDiepte(int d)
{
  m_scanDiepte = d;
}
/* leest de waardes van de linker en rechter proximity sensors in*/
void ObjectDetector::scan()
{
  m_proximitySensor.read();
  m_readingsLeftLed = m_proximitySensor.countsFrontWithLeftLeds();
  m_readingsRightLed = m_proximitySensor.countsFrontWithRightLeds();
}

/* returned een bool die aangeeft of er een object binnen de scandiepte staat */
bool ObjectDetector::objectGedetecteerd() const
{
  return (m_readingsLeftLed == m_scanDiepte || m_readingsRightLed == m_scanDiepte);
}

/* gebruikt de waardes van scan om te bepalen of het object links of rechts staat in vergelijking met de Zumo */
Richting ObjectDetector::objectRichting() const
{
  if(objectGedetecteerd())
  {
    if(m_readingsLeftLed > m_readingsRightLed)
    {
      return Richting::Links;
    }
    if(m_readingsLeftLed < m_readingsRightLed)
    {
      return Richting::Rechts;
    }
    if(m_readingsLeftLed == m_readingsRightLed) 
    {
      return Richting::Midden;
    }
  }
  else
  {
    return Richting::Geen;
  }
}
