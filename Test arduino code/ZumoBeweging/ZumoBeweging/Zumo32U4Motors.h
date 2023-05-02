
 #pragma once
  
 #include <stdint.h>
  
 class Zumo32U4Motors
 {
   public:
  
     static void linksAf(bool links);
  
     static void rechtsAf(bool rechts);
  
     static void linkerSnelheid(int16_t snelheid);
  
     static void rechterSnelheid(int16_t snelheid);
  
     static void kiesSnelheid(int16_t linkerSnelheid, int16_t rechterSnelheid);
  
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