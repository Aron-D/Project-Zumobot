#include "Zumo32U4Motors.h"

void Zumo32U4Motors::init() {
  // Initialize the motor pins
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);

  // Set the motor speeds to zero
  setSpeeds(0, 0);
}

void Zumo32U4Motors::setSpeeds(int16_t leftSpeed, int16_t rightSpeed) {
  // Set the left motor speed
  setSpeed(0, leftSpeed);

  // Set the right motor speed
  setSpeed(1, rightSpeed);
}

void Zumo32U4Motors::setSpeed(uint8_t motor, int16_t speed) {
  // Determine the direction of the motor
  bool reverse = speed < 0;

  // Set the PWM pin for the motor
  uint8_t pwmPin = motor == 0 ? 5 : 6;

  // Set the direction pin for the motor
  uint8_t dirPin = motor == 0 ? 10 : 9;

  // Set the direction of the motor
  digitalWrite(dirPin, reverse ? HIGH : LOW);

  // Set the speed of the motor
  analogWrite(pwmPin, abs(speed));
}
