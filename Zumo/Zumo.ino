#include "LijnSensor.h"
#include "ObjectDetector.h"
#include "AccelSensor.h"
#include "Kompas.h"

AccelSensor accelSensor;
LijnSensor lijnSensor;
ObjectDetector objectDetector;
Kompas kompas;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  //AccelSensor setup
  accelSensor.init();

  //LijnSensor setup
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_calibreren();

  //Kompas setup
  kompas.init(WEL_OOG_ZUMO_CALIBRATION_MIN, WEL_OOG_ZUMO_CALIBRATION_MAX);
}

void loop() 
{
  //voorbeeld code LijnSensor
  Serial.println(lijnSensor.lijn_positie());

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

  // voorbeeld code AccelSensor
  // Accel_ReturnPosition() print al automatisch de positie
  accelSensor.Accel_ReturnPosition(); 

  // voorbeeld code Kompas
  // aan het einde \n zodat er ruimte zit tussen de regels
  Serial.println(kompas.graden()); 

  delay(50);
}
