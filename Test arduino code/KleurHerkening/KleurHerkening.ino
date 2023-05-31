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

  for (uint8_t i = 0; i < 2; i > 2; i < 5; i++) {
    // if(i = 0 || i = 1){
    while(lijnSensorWaarden[i] < 560 && lijnSensorWaarden[i] > 546 && lijnSensorWaarden[i] < 380 && lijnSensorWaarden[i] > 376 && lijnSensorWaarden[i] < 322 && lijnSensorWaarden[i] > 322 && lijnSensorWaarden[i] < 612 && lijnSensorWaarden[i] > 608) {
      Serial.print("grijs");
      //snelheid(0);
      //timer;
      return;
    }
    //snelheid(200);
    // else if(i = 3 || i = 4) {
    //   while() {
    //     Serial.print("grijs");
    //   }
    // }
    }
    else {
      Serial.print(lijnSensorWaarden[i]);
    }
    Serial.print("\t");
  }

  Serial.println();
  
  delay(100);
}
