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

static constexpr LSM303::vector<int16_t> WEL_OOG_ZUMO_CALIBRATION_MIN = {-4572,  -7623,   +301};
static constexpr LSM303::vector<int16_t> WEL_OOG_ZUMO_CALIBRATION_MAX = {+2452,  -1781, +11243};
static constexpr LSM303::vector<int16_t> NIET_OOG_ZUMO_CALIBRATION_MIN = {-6091,  -4150,  +2725};
static constexpr LSM303::vector<int16_t> NIET_OOG_ZUMO_CALIBRATION_MAX = {+1524,  +1816, +13605};

class Kompas
{
private:
//attribuut van de library LSM303. hier kan/mag niet bewerkt worden
  LSM303 compass;
public:
//eigen attributen. dit kan bewerkt worden in de Kompas.ino bestand
  Kompas();
  void init(LSM303::vector<int16_t> min, LSM303::vector<int16_t> max);
  float graden();
  void calibreer();
};

#endif

