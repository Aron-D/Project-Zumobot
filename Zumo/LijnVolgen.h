#include "Motoren.h"
#include "LijnSensor.h"

#ifndef LIJNVOLGEN_H
#define LIJNVOLGEN_H

class LijnVolgen
{
    public:
      LijnVolgen();
      void init();
      void start();
      void kiesBocht();
    private:
      Motoren motoren;
      LijnSensor lijnsensor;
      int16_t lastError;
      int16_t error;
      int16_t maxSpeed;
};

#endif
