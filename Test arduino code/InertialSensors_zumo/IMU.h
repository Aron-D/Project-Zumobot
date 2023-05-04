
// #ifndef IMU_H
// #define IMU_H

#include <Wire.h>
#include <Zumo32U4.h>

class IMU {
  private:
    Zumo32U4IMU imu;

  public:
    IMU();
    void begin();
    void update();
};

// #endif


IMU::IMU() 
{}

void IMU::begin() {
  Wire.begin();

  if (!imu.init())
  {
    // Failed to detect the compass.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to initialize IMU sensors."));
      delay(100);
    }
  }

  imu.enableDefault();
}

void IMU::update() {
  imu.read();

  char report[120];
  snprintf_P(report, sizeof(report),
    PSTR("G: %6d %6d %6d"),
    imu.g.x, imu.g.y, imu.g.z);
  Serial.println(report);

  delay(100);
}
