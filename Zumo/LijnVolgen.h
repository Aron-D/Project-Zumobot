#include "Motoren.h"
#include "LijnSensor.h"

#ifndef LIJNVOLGEN_H
#define LIJNVOLGEN_H

class LijnVolgen {
    public:
      LijnVolgen();
      void init();
      void volg();
    private:
      Motoren motoren;
      LijnSensor lijnsensoren;
};

#endif
