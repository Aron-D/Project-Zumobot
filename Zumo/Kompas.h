/*!
  @file Heading.ino
  @date 5 May 2023
  @author Aron Dosti

*/

#ifndef __kompas__
#define __kompas__ 

//classes met eigen attributen die bruikbaar zijn
#include <LSM303.h>
#include <Wire.h>

class Kompas
{
private:
  //attribuut van de library LSM303. hier kan/mag niet bewerkt worden
  LSM303 compass;

  //kompas kalibratie waarden
  const LSM303::vector<int16_t> ZUMO_EEN_CALIBRATION_MIN = {-4572,  -7623,   +301}; //zumo 1 is met ogen
  const LSM303::vector<int16_t> ZUMO_EEN_CALIBRATION_MAX = {+2452,  -1781, +11243};
  const LSM303::vector<int16_t> ZUMO_TWEE_CALIBRATION_MIN = {-6091,  -4150,  +2725}; //zumo 2 is zonder ogen
  const LSM303::vector<int16_t> ZUMO_TWEE_CALIBRATION_MAX = {+1524,  +1816, +13605};
public:
  //eigen attributen. dit kan bewerkt worden in de Kompas.ino bestand
  Kompas();
  void init();
  float graden();
  //void calibreer();
};

#endif

