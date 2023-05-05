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
public:
//eigen attributen. dit kan bewerkt worden in de Kompas.ino bestand
  Kompas();
  float graden();
  void calibreer();
  void init();

};

#endif

