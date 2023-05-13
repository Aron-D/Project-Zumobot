#include <Zumo32U4.h>

#include "LijnSensor.h"
#include "ObjectDetector.h"
#include "AccelSensor.h"
#include "Kompas.h"
#include "Motoren.h"

Zumo32U4ButtonA buttonA;

AccelSensor accelSensor;
LijnSensor lijnSensor;
ObjectDetector objectDetector;
Kompas kompas;
Motoren motor;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  //wacht totdat gebruiker serial monitor opent
  while(!Serial);

  //AccelSensor setup
  accelSensor.init();

  //LijnSensor setup
  Serial.println("druk op A om lijnsensor te kalibreren...");
  if(buttonA.getSingleDebouncedPress())
  {
    lijnSensor.sensoren_initialiseren();
    lijnSensor.sensoren_kalibreren(motor);
    Serial.println("lijnsensor gekalibreert");
  }
  
  //Kompas setup
  Serial.println("druk op A om kompas te kalibreren...");
  if(buttonA.getSingleDebouncedPress())
  {
    kompas.init();
    //kompas.kalibreren();
    Serial.println("kompas gekalibreert");
  }
}

void loop() 
{
  //voorbeeld code LijnSensor
  Serial.println(lijnSensor.lijn_error());

  //voorbeeld code ObjectDetector
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

  // voorbeeld code Kompas
  //aan het einde \n zodat er ruimte zit tussen de regels
  Serial.println((String)kompas.graden() + "\n"); 

  delay(200);
}
