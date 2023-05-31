#include "LijnVolgen.h"

LijnVolgen::LijnVolgen() {}

void LijnVolgen::init() {
  //lijnSensor setup
  lijnsensor.sensoren_initialiseren();
  lijnsensor.sensoren_kalibreren(motoren);
}

void LijnVolgen::volgExample() {
  // Get motor speed difference using proportional and derivative
  // PID terms (the integral term is generally not very useful
  // for line following).  Here we are using a proportional
  // constant of 1/4 and a derivative constant of 6, which should
  // work decently for many Zumo motor choices.  You probably
  // want to use trial and error to tune these constants for your
  // particular Zumo and line course.
  int error = lijnsensor.lijn_error();
  int16_t speedDifference = error / 4'0 + 6 * (error - lastError);

  lastError = error;

  // Get individual motor speeds.  The sign of speedDifference
  // determines if the robot turns left or right.
  int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
  int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

  // Constrain our motor speeds to be between 0 and maxSpeed.
  // One motor will always be turning at maxSpeed, and the other
  // will be at maxSpeed-|speedDifference| if that is positive,
  // else it will be stationary.  For some applications, you
  // might want to allow the motor speed to go negative so that
  // it can spin in reverse.
  leftSpeed = constrain(leftSpeed, -maxSpeed, maxSpeed);
  rightSpeed = constrain(rightSpeed, -maxSpeed, maxSpeed);

  motoren.setSpeeds(leftSpeed, rightSpeed);
}

/* void LijnVolgen::volg() {
  if (lijnsensor.lijn_error() < 0) {
    motoren.rijLinks(abs(lijnsensor.lijn_error()) / 10);
  }
  else if (lijnsensor.lijn_error() > 0) {
    motoren.rijRechts(abs(lijnsensor.lijn_error()) / 10);
  }
  else {
    motoren.rechtdoor(200);
  }
} */

void LijnVolgen::volg() {
  Serial.println(lijnsensor.lijn_error());
  if (lijnsensor.lijn_error() < -400 && lijnsensor.lijn_error() > -1500) {
      motoren.rijLinks(150);
      //volgExample();
    }
    else if (lijnsensor.lijn_error() < -1500 && lijnsensor.lijn_error() > -2000) {
      motoren.draaiLinks(150);
    }
    else if (lijnsensor.lijn_error() > 400 && lijnsensor.lijn_error() < 1500) {
      motoren.rijRechts(150);
      //volgExample();
    }
    else if (lijnsensor.lijn_error() > 1500 && lijnsensor.lijn_error() < 2000) {
      motoren.draaiRechts(150);
    }
    else {
      motoren.rechtdoor(150);
      //volgExample();
    }
}
//in testing phase excuse the stoopid code
void LijnVolgen::kiesBocht() {

for (uint8_t i = 0; i < 5; i++) {
  if (i = 0)
    if (lijnSensorWaarden[i] < 570 && lijnSensorWaarden[i] > 540) {
      volgendebocht = "links";
      serial.println(volgendebocht)
    }
 if (i = 4)
    if (lijnSensorWaarden[i] < 620 && lijnSensorWaarden[i] > 600) {
      volgendebocht = "rechts";
      serial.println(volgendebocht)
    }
}
