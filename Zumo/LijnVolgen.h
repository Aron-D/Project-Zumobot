#include "Motoren.h"
#include "LijnSensor.h"

#ifndef LIJNVOLGEN_H
#define LIJNVOLGEN_H

class LijnVolgen {
    public:
      LijnVolgen();
      void init();
      void volg();
      void volgExample();
      void kiesBocht();
    private:
      Motoren motoren;
      LijnSensor lijnsensor;
      String volgendeBocht;
      const int16_t maxSpeed = 400;
      int lastError = 0;
};

#endif
