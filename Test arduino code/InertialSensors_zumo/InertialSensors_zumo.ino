#include "IMU.h"

IMU imu;

void setup() {
  imu.begin();
}

void loop() {
  imu.update();
}

