/*!
  @file AccelSensor.h
  @date 5 May 2023
  @author Ziggy Gerbrands
  
*/

#ifndef ACCELSENSOR_H
#define ACCELSENSOR_H

#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4IMU.h>

class AccelSensor {
  public:
    AccelSensor();
    String Accel_ReturnPosition();
    int Accel_ReturnX();
    int Accel_ReturnY();
    int Accel_ReturnZ();

  private:
    Zumo32U4IMU Zumo;
    int LastXValue;
    int LastYValue;
    int LastZValue;
};

#endif