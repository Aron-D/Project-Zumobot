/*!
  @file AccelSensor_Zumo.ino
  @date 5 May 2023
  @author Ziggy Gerbrands

*/
  





#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4IMU.h>



Zumo32U4IMU Zumo;
int LastXValue = 0;
int LastYValue = 0;
int LastZValue = 0;




void setup() {
Zumo.enableDefault();
Wire.begin();
Zumo.init();



}

void loop() {
Zumo.readAcc();
LastXValue = Zumo.a.x;
LastYValue = Zumo.a.y;
LastZValue = Zumo.a.z;

if (LastXValue < -16000) {
  Serial.println("Voorkant");
}
if (LastXValue > 16000) {
  Serial.println("Achterkant");
}

if (LastYValue < -16000) {
  Serial.println("Linkerzijde");
}
if (LastYValue > 16000) {
  Serial.println("rechterzijde");
}

if (LastZValue < -16000) {
  Serial.println("Zumo ligt ondersteboven!");
}

if (LastZValue > 16000) {
  Serial.println("Zumo staat recht!");
}
delay(500);
}






