#include "ObjectDetector.h"

/*! Constructor voor Objectdetector */
ObjectDetector::ObjectDetector()
{
  m_proximitySensor.initThreeSensors();
  m_scanDiepte = 5;
}

/*!
Zet de scandiepte van de zumo gelijk aan het meegegeven getal.
De scan diepte is een getal van 1-6, hoe lager hoe verder hij kan zien  
*/
void ObjectDetector::setScanDiepte(int d)
{
  m_scanDiepte = d;
}

/*! Leest de waardes van de linker en rechter proximity sensors in */
void ObjectDetector::scan()
{
  m_proximitySensor.read();
  m_readingsLeftLed = m_proximitySensor.countsFrontWithLeftLeds();
  m_readingsRightLed = m_proximitySensor.countsFrontWithRightLeds();
}

/*! Return een bool die aangeeft of er een object binnen de scandiepte staat */
bool ObjectDetector::objectGedetecteerd() const
{
  return (m_readingsLeftLed == m_scanDiepte || m_readingsRightLed == m_scanDiepte);
}

/*!
Gebruikt de waardes van scan om te bepalen of het object links of rechts staat in vergelijking met de Zumo
Return de richting van het object  in vergelijking met de Zumo, return Geen als er geen object gedetecteerd is.
*/
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
