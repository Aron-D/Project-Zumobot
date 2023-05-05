#include "LijnSensor.h"
#include "ObjectDetector.h"

LijnSensor lijnSensor;
ObjectDetector objectDetector;

void setup() 
{
  // put your setup code here, to run once:
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_calibreren();
}

void loop() 
{
  objectDetector.scan();

  // put your main code here, to run repeatedly:
  if(LijnSensor.lijn_positie() == 0 && !objectDetector.objectGedetecteerd())
  {
    Serial.println("De zumo rijdt vooruit");
  }
}
