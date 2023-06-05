/*!
  @file Gyro.ino
  @date 23 May 2023
  @author Ziggy Gerbrands
  
  had only 1 pramary function at the moment
  reads the Y value of the Gyro and returns the current position relative to the Y axis

*/

#include "Gyro.h"
#include <Zumo32U4IMU.h>
Gyro::Gyro() {

};

String Gyro::ReturnAngle() {
  // reads the gyro values
  imu.read();

  
    // converts the value of the y axis to a more easy to read value and stores it in Lastrotation
    int yrotatie =  imu.g.y /100;
    String Lastrotation;

    // converts the value into the current position and returns the position as an String
    if (yrotatie < 0 && yrotatie > -7) {
      Serial.println("Neutral Position");
      return ("neutral");
    }
    if (yrotatie < -100){
      Serial.println("Rotating Y Up!");
      Lastrotation = ("up");
      return ("up");
    }
    if (yrotatie > 100){
      Serial.println("Rotation Y Down!");
      Lastrotation = ("down");
      return ("down");
    }
    else{
      return ("error");
    }
}