/*!
  @file Heading.ino
  @date 5 May 2023
  @author Aron Dosti

*/

//uitroep h file voor class Kompas
#include "Kompas.h"

//uitroep constructor. dit kan in de toekomst verder worden uitgebreid en gebruikt worden in de Heading.ino
Kompas::Kompas()
{}

//de constructor voor de void setup in Heading.ino
void Kompas::init(LSM303::vector<int16_t> min, LSM303::vector<int16_t> max)
{
  compass.init();
  compass.enableDefault();
  //configuratie dat na calibratie accuraat opgesteld kan worden door de waarde te vervangen met de waarde van de magnetometer
  compass.m_min = min;
  compass.m_max = max;
}

//de constructor voor de void loop in Heading.ino
float Kompas::graden()
{
  //uitlezen compass attribuut
  compass.read();
  return compass.heading();
}

//voor het calibreren om de accuratie van de graden kompas juist te krijgen.
//dit is nodig om bij Kompas::init() de minimum en maximum waarde te vervangen met de waarde van de calibratie.
//Deze functie geeft compiler errors omdat running_min en running_max nergens gedefinieerd zijn... 
void Kompas::calibreer()
{
//  compass.read();
//  //opmeting minimum x,y,z waarde van de magnetometer in de compass attribuut
//  running_min.x = min(running_min.x, compass.m.x);
//  running_min.y = min(running_min.y, compass.m.y);
//  running_min.z = min(running_min.z, compass.m.z);
//
////opmeting maximum x,y,z waarde van de magnetometer in de compass attribuut
//  running_max.x = max(running_max.x, compass.m.x);
//  running_max.y = max(running_max.y, compass.m.y);
//  running_max.z = max(running_max.z, compass.m.z);
//  
//  //voor het tonen van de uiteindelijke waarde in de seriele monitor
//  snprintf(report, sizeof(report), "min: {%+6d, %+6d, %+6d}    max: {%+6d, %+6d, %+6d}",
//    running_min.x, running_min.y, running_min.z,
//    running_max.x, running_max.y, running_max.z);
//  Serial.println(report);
}

