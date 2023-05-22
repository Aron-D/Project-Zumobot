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

  for (uint8_t i = 0; i < 5; i++) {
    if (lijnSensorWaarden[i] < 700 && lijnSensorWaarden[i] > 470) {
      Serial.print("grijs");
    }
    else {
      Serial.print(lijnSensorWaarden[i]);
    }
    Serial.print("\t");
  }

  Serial.println();
  
  delay(100);
}
