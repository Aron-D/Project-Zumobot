#include "ObjectDetector.h"

ObjectDetector detector;

void setup() {}

void loop() 
{
  detector.scan();
  if(detector.objectRichting() == Richting::Links) Serial.println("object gedetecteerd links");
  if(detector.objectRichting() == Richting::Rechts) Serial.println("object gedetecteerd rechts");
  if(detector.objectRichting() == Richting::Midden) Serial.println("object gedetecteerd midden");
  if(detector.objectRichting() == Richting::Geen) Serial.println("geen object gedetecteerd");
}
