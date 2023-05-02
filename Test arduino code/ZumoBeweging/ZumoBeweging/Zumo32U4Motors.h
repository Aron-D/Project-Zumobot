
 #pragma once
  
 #include <stdint.h>
  
 class Zumo32U4Motors
 {
   public:
  
     static void flipLeftMotor(bool flip);
  
     static void flipRightMotor(bool flip);
  
     static void setLeftSpeed(int16_t speed);
  
     static void setRightSpeed(int16_t speed);
  
     static void setSpeeds(int16_t leftSpeed, int16_t rightSpeed);
  
   private:
  
     static inline void init()
     {
         static bool initialized = false;
  
         if (!initialized)
         {
             initialized = true;
             init2();
         }
     }
  
     static void init2();
 };