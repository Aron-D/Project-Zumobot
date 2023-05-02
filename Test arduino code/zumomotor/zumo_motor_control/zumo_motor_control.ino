#include <Zumo32U4Motors.h>

Zumo32U4Motors motors;

void setup() {
  // Initialize the motor library
  motors.init();
}

void loop() {
  // Move the robot forward for one second
  motors.setSpeeds(400, 400);
  delay(1000);

  // Move the robot backward for one second
  motors.setSpeeds(-400, -400);
  delay(1000);

  // Turn the robot left for one second
  motors.setSpeeds(-400, 400);
  delay(1000);

  // Turn the robot right for one second
  motors.setSpeeds(400, -400);
  delay(1000);
}
