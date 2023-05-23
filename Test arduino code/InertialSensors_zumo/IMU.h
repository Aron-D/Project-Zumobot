
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
    // Mislukt om sensor te detecteren.
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

  
  
    int yrotatie =  imu.g.y /100;
    String Lastrotation;

    if (yrotatie < 0 && yrotatie > -7) {
      Serial.println("Neutral Position");

    }
    if (yrotatie < -100){
      Serial.println("Rotating Y Up!");
      Lastrotation = ("up");
    }
    if (yrotatie > 100){
      Serial.println("Rotation Y Down!");
      Lastrotation = ("down");
    }
    else{
      return false;
    }

  delay(300);
}
