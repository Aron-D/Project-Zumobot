/*!
  @file Gyro.h
  @date 23 May 2023
  @author Ziggy Gerbrands
  
*/

#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4IMU.h>

class Gyro
{
  public:
  Gyro();
  String ReturnAngle();

  private:
  String LastAngle();
  int Yrotation();
}