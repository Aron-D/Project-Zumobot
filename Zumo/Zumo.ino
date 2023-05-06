#include "LijnSensor.h"
#include "ObjectDetector.h"
#include "AccelSensor.h"
#include "Kompas.h"

LijnSensor lijnSensor;
ObjectDetector objectDetector;
AccelSensor accelSensor;
Kompas kompas;

void setup() 
{
  //LijnSensor setup
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_calibreren();

  //Kompas setup
  kompas.init();
}

void loop() 
{
  //voorbeeld code LijnSensor
  Serial.println("afwijking van de lijn: " + lijnSensor.lijn_positie());

  //voorbeeld code ObjectDetector
  objectDetector.scan();
  if(objectDetector.objectGedetecteerd())
  {
    Serial.println("er is een object gedetecteerd");
  }
  else 
  {
    Serial.println("er is geen object gedetecteerd");
  }

  //voorbeeld code AccelSensor
  //Accel_ReturnPosition() print al automatisch de positie
  accelSensor.Accel_ReturnPosition(); 

  //voorbeeld code Kompas
  //aan het einde \n zodat er ruimte zit tussen de regels
  Serial.println("aantal graden gedraait vanaf noord" + (String)kompas.graden() + "\n"); 
}
