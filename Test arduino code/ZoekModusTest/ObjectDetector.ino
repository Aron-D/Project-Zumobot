#include "ObjectDetector.h"

ObjectDetector::ObjectDetector()
{
  m_proximitySensor.initThreeSensors();
  m_scanDiepte = 6;
}

void ObjectDetector::setScanDiepte(int d)
{
  m_scanDiepte = d;
}

void ObjectDetector::scan()
{
  m_proximitySensor.read();
  m_readingsLeftLed = m_proximitySensor.countsFrontWithLeftLeds();
  m_readingsRightLed = m_proximitySensor.countsFrontWithRightLeds();
}

bool ObjectDetector::objectGedetecteerd() const
{
  return (m_readingsLeftLed == m_scanDiepte || m_readingsRightLed == m_scanDiepte);
}

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
