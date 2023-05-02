#ifndef ZUMO32U4MOTORS_H
#define ZUMO32U4MOTORS_H

#include <Arduino.h>

class Zumo32U4Motors {
  public:
    void init();
    void setSpeeds(int16_t leftSpeed, int16_t rightSpeed);
  private:
    void setSpeed(uint8_t motor, int16_t speed);
};

#endif