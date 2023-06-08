#include <Zumo32U4LineSensors.h>
#include <stdio.h>

Zumo32U4LineSensors lijnSensoren;
uint16_t lijnSensorWaarden[5];

void setup() {
  Serial.begin(9600);
  lijnSensoren.initFiveSensors();
}

void loop() {
  lijnSensoren.read(lijnSensorWaarden);
  int senslinks = lijnSensorWaarden[0];
  int sensrechts = lijnSensorWaarden[4];

    //  if (senslinks < 560 && senslinks > 546 && lijnSensorWaarden[i] < 380 && lijnSensorWaarden[i] > 376 && lijnSensorWaarden[i] < 322 && lijnSensorWaarden[i] > 322 && lijnSensorWaarden[i] < 612 && lijnSensorWaarden[i] > 608) {

     if (senslinks < 320 && senslinks > 250 && sensrechts < 480 && sensrechts > 450) {
       Serial.println("ik zie grijs!");
      
     } else {
      Serial.println("niks te zien");
      }
    // Serial.println(sensrechts);
      //snelheid(0);
      //timer;
      // return;
    // }    
    // }
    // if(i = 0 || i = 1){

    //snelheid(200);
    // else if(i = 3 || i = 4) {
    //   while() {
    //     Serial.print("grijs");
      }
    
    
    // Serial.print("\t");
  

  // Serial.println();
  
  // delay(100);
// }

