/*!
  @file AccelSensor_Zumo.ino
  @date 5 May 2023
  @author Ziggy Gerbrands

*/

#include "AccelSensor_Zumo.h"


AccelSensor::AccelSensor() {

};


String AccelSensor::Accel_ReturnPosition() {

  Zumo.readAcc();
  LastXValue = Zumo.a.x;
  LastYValue = Zumo.a.y;
  LastZValue = Zumo.a.z;


  if (LastXValue < -16000) {
  Serial.println("Voorkant");
  return ("Voorkant");
}
  if (LastXValue > 16000) {
  Serial.println("Achterkant");
  return ("Achterkant");
}

  if (LastYValue < -16000) {
  Serial.println("Linkerzijde");
  return ("Linkerzijde");
}
  if (LastYValue > 16000) {
  Serial.println("rechterzijde");
  return ("Linkerzijde");
}
  if (LastZValue < -16000) {
  Serial.println("Zumo ligt ondersteboven!");
  return ("Zumo ligt ondersteboven!");
}
  if (LastZValue > 16000) {
  Serial.println("Zumo staat recht!");
  return ("Zumo staat recht!");

}
}
int AccelSensor::Accel_ReturnX() {
  Zumo.readAcc();
  LastXValue = Zumo.a.x;
  return LastXValue;
}
int AccelSensor::Accel_ReturnY() {
  Zumo.readAcc();
  LastYValue = Zumo.a.y;
  return LastYValue;
}
int AccelSensor::Accel_ReturnZ() {
  Zumo.readAcc();
  LastZValue = Zumo.a.z;
  return (LastZValue);
}

