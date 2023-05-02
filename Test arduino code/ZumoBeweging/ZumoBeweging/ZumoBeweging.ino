#include <Zumo32U4.h>
#include <Zumo32U4Motors.h>

Zumo32U4ButtonA buttonA;

Zumo32U4Motors motors;

const uint16_t motorSnelheid = 100;

void setup() {
 
}

void loop() {

  
  bool buttonPress = buttonA.getSingleDebouncedPress();
  
  if (buttonPress) {
  
    delay(1000);

  //vooruit voor 2 seconde
    motors.setSpeeds(motorSnelheid, motorSnelheid);
    delay(2000);

    
    motors.setSpeeds(0, 0);
    delay(500);

    // achteruit voor 2 seconde
    motors.setSpeeds(-motorSnelheid, -motorSnelheid);
    delay(2000);

    // Stop
    motors.setSpeeds(0, 0);
    delay(500);

    // links voor 2 seconde
    motors.setSpeeds(-motorSnelheid, motorSnelheid);
    delay(1000);    

    // Stop
    motors.setSpeeds(0, 0);
  }
}