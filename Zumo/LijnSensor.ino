/*!
  @file LijnSensor.ino
  @author Ruben van Eijken

  Implementatie van de klasse "LijnSensor".
*/

#include "LijnSensor.h"

LijnSensor::LijnSensor() {}

/*! Vertelt de Zumo dat alle vijf de lijnsensoren gebruikt moeten worden. */
void LijnSensor::initialiseren()
{
  lijnSensoren.initFiveSensors();
}

/*! Calibratie door metingen uit te lezen van de lijnsensoren en vervolgens te bepalen wat "licht" en "donker" is. */
void LijnSensor::kalibreren(Motoren& m)
{
  Zumo32U4Buzzer buzzer;

  Serial.println("Kleuren kalibratie");

  /*
  //kalibreer kleur detectie zwart
  Serial.println("Zet de zumo op een zwarte lijn");
  delay(3000);
  buzzer.playFrequency(220, 200, 15); //begin kalibreren
  kalibreer_kleuren(zwartMaximumWaarde, zwartMaximumWaarde, m);
  buzzer.playFrequency(440, 200, 15); //eind kalibreren
  */
  
  /*
  //kalibreer kleur detectie grijs
  Serial.println("Zet de zumo op een grijze lijn");
  delay(3000);
  buzzer.playFrequency(220, 200, 15); //begin kalibreren
  kalibreer_kleuren(grijsMinimumWaarde, grijsMaximumWaarde, m);
  buzzer.playFrequency(440, 200, 15); //eind kalibreren
  */
  
  /*
  //kalibreer kleur detectie bruin
  Serial.println("Zet de zumo op een bruine lijn");
  delay(3000);
  buzzer.playFrequency(220, 200, 15); //begin kalibreren
  kalibreer_kleuren(bruinMinimumWaarde, bruinMaximumWaarde, m);
  buzzer.playFrequency(440, 200, 15); //eind kalibreren
  */

  /*
  //kalibreer kleur detectie groen
  Serial.println("Zet de zumo op een groene lijn");
  delay(3000);
  buzzer.playFrequency(220, 200, 15); //begin kalibreren
  kalibreer_kleuren(groenMinimumWaarde, groenMaximumWaarde, m);
  buzzer.playFrequency(440, 200, 15); //eind kalibreren
  */

  /*
  //kalibreer kleur detectie zwart
  Serial.println("\nLijn kalibratie");
  Serial.println("Zet de zumo op een zwarte lijn");
  delay(3000);
  buzzer.playFrequency(220, 200, 15);
  */

  delay(2000);

  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      m.draaiLinks(200);
    }
    else
    {
      m.draaiRechts(200);
    }
    lijnSensoren.calibrate();
  }
  m.stop();
  buzzer.playFrequency(440, 200, 15);
}

void LijnSensor::kalibreer_kleuren(int& min, int& max, Motoren& m)
{
  uint16_t kleursensors[5];
  min = 1023;
  max = 0;

  for(uint16_t i = 0; i < 120; i++)
  {
    lijnSensoren.read(kleursensors);
    if(kleursensors[0] < min) { min = kleursensors[0]; }
    if(kleursensors[0] > max) { max = kleursensors[0]; }
    Serial.println("min: " + String(min) + ", max: " + String(max) + " --- " + String(kleursensors[0]));
    delay(10);
  }
}

String LijnSensor::lees_kleur(int sensor_nummer)
{
  uint16_t kleursensors[5];
  lijnSensoren.read(kleursensors);
  int marge = 50;

  if(kleursensors[sensor_nummer] > bruinMinimumWaarde-marge && kleursensors[sensor_nummer] < bruinMaximumWaarde+marge)
  {
    return "bruin";
  }

  if(kleursensors[sensor_nummer] > groenMinimumWaarde-marge && kleursensors[sensor_nummer] < groenMaximumWaarde+marge)
  {
    return "groen";
  }

  if(kleursensors[sensor_nummer] > grijsMinimumWaarde-marge && kleursensors[sensor_nummer] < grijsMaximumWaarde+marge)
  {
    return "grijs";
  }
  
  if(kleursensors[sensor_nummer] > zwartMinimumWaarde-marge && kleursensors[sensor_nummer] < zwartMaximumWaarde+marge)
  {
    return "zwart";
  }
  return "";
}

/*! Geeft de afstand tot de lijn. */
int LijnSensor::error()
{
  return lijnSensoren.readLine(sensorWaarden) - 2000;
}

/*! Leest de individuele lijnsensoren uit. */
int LijnSensor::lees_sensor(int i)
{
  lijnSensoren.read(sensorWaarden);
  return sensorWaarden[i];
}
