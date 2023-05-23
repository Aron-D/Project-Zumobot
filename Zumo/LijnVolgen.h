#include "Motoren.h"
#include "LijnSensor.h"

#ifndef LIJNVOLGEN_H
#define LIJNVOLGEN_H

class LijnVolgen {
    public:
      LijnVolgen();
      void init();
      void volg();
      void kiesBocht();
    private:
      Motoren motoren;
      LijnSensor lijnsensor;
      String volgendeBocht;
};

#endif
