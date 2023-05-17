#include <Zumo32U4.h>

#include "LijnSensor.h"
#include "ObjectDetector.h"
#include "AccelSensor.h"
#include "Motoren.h"

AccelSensor accelSensor;
LijnSensor lijnSensor;
ObjectDetector objectDetector;
Motoren motor;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  //AccelSensor setup
  accelSensor.init();

  //lijnSensor setup
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_kalibreren(motor);
}

void loop() 
{
  //voorbeeld code LijnSensor
  Serial.println(lijnSensor.lijn_error());
  //voorbeeld code ObjectDetector en Motoren
  objectDetector.scan();
  if(objectDetector.objectGedetecteerd())
  {
    Serial.println("er is een object gedetecteerd");
    motor.stop();
  }
  else 
  {
    Serial.println("er is geen object gedetecteerd");
    motor.rechtdoor(200);
  }
  // voorbeeld code AccelSensor
  // Accel_ReturnPosition() print al automatisch de positie
  accelSensor.Accel_ReturnPosition(); 

  delay(200);
}
