#include <Zumo32U4.h>

#include "LijnSensor.h"
#include "Motoren.h"

LijnSensor lijnSensor;
Motoren motor;

void setup() 
{
  lijnSensor.sensoren_initialiseren();
  lijnSensor.sensoren_kalibreren(motor);
}

void loop() 
{
  
}
