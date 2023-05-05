/*!
  @file AccelSensor_Zumo.ino
  @date 5 May 2023
  @author Ziggy Gerbrands
  
  Has 2 primary functions regarding the Accelorometer in a Zumo-Style bot.
  Returns the current downward facing side of the zumo in the class Accel_ReturnPosition
  Returns the X,Y,Z Values of the Accelorometer in the classes Accel_ReturnX/Y/Z

*/

#include "AccelSensor_Zumo.h"


AccelSensor::AccelSensor() { 

};


String AccelSensor::Accel_ReturnPosition() { // class that reads the current X,Y,Z values of the accelorometer and converts it to positions in strings.

// reads the current values of the accelorometer and saves the values in intergers (Last(X,Y,Z)Value)
  Zumo.readAcc();
  LastXValue = Zumo.a.x;
  LastYValue = Zumo.a.y;
  LastZValue = Zumo.a.z;

// returns the position facing downward depending on the values stored above, also prints the position to the serial port.
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


// group of classes that return only the value stored in the intergers.
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

