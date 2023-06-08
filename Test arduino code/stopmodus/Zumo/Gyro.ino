// /*!
//   @file Gyro.ino
//   @date 23 May 2023
//   @author Ziggy Gerbrands
  
//   had only 1 pramary function at the moment
//   reads the Y value of the Gyro and returns the current position relative to the Y axis

// */
// #include <Zumo32U4IMU.h>
// #include "Gyro.h"
// void Gyro::init() {
//  Wire.begin();

//   if (!imu.init())
//   {
//     // Failed to detect the compass.
//     ledRed(1);
//     while(1)
//     {
//       Serial.println(F("Failed to initialize IMU sensors."));
//       delay(100);
//     }
//   }

//   imu.enableDefault();
// };

// int Gyro::ReturnAngle() {
//   // reads the gyro values
//   imu.read();

  
//     // converts the value of the y axis to a more easy to read value and stores it in Lastrotation
    
//     // String Lastrotation;

//     // converts the value into the current position and returns the position as an String
//     // if (yrotatie < 0 && yrotatie > -7) {
//     //   Serial.println("Neutral Position");
//     //   return ("neutral");
//     // }
//     // if (yrotatie < -100){
//     //   Serial.println("Rotating Y Up!");
//     //   Lastrotation = ("up");
//     //   return (Lastrotation);
//     // }
//     // if (yrotatie > 100){
//     //   Serial.println("Rotation Y Down!");
//     //   Lastrotation = ("down");
//     //   return (Lastrotation);
//     // }
//     char report[120];
//   snprintf_P(report, sizeof(report),
//     PSTR("G: %6d "),
//     imu.g.y);
//     int yrotatie =  imu.g.y /100;
//     while(yrotatie <)
//   Serial.println(yrotatie);

//     // if (yrotatie){
//       //  Serial.println(yrotatie);
//       //  return;
//     //  }
//     // else{
//       // return "error";
//     // }
// }