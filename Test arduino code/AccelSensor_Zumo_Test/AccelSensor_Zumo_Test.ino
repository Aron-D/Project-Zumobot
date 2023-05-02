#include <Wire.h>
#include <Zumo32U4.h>
#include <Zumo32U4IMU.h>



Zumo32U4IMU Zumo;
int LastXValue = 0;
int LastYValue = 0;
int LastZValue = 0;

int NewXValue = 0;
int NewYValue = 0;
int NewZValue = 0;

void setup() {
Zumo.enableDefault();
Wire.begin();
Zumo.init();


}

void loop() {
Zumo.readAcc();


if (Zumo.accDataReady() == 1) {
  NewXValue = Zumo.a.x;
  NewYValue = Zumo.a.y;
  NewZValue = Zumo.a.z;
 switch (LastXValue, LastYValue, LastZValue, NewXValue, NewYValue, NewZValue) {
   case NewXValue > LastXValue:
   Serial.println("Forward");
   break;

   case NewXValue < LastXValue:
   Serial.println("Backwards");
   break;

   case NewYValue > LastYValue:
   Serial.println("Up");
   break;

   case NewYValue < LastYValue:
   Serial.println("Down");
   break;

   case NewZValue > LastZValue:
   Serial.println("Left");
   break;

   case NewZValue < LastZValue:
   Serial.println("Right");
   break;
 }
}
LastXValue = Zumo.a.x;
LastYValue = Zumo.a.y;
LastZValue = Zumo.a.z;
}
