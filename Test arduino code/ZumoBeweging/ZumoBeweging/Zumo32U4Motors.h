

  
 #include <stdint.h>
  
 class Zumo32U4Motors
 {
   public:
  
      linksAf(bool links);

      rechtsAf(bool rechts);
  
      linkerSnelheid(int16_t snelheid);
  
      rechterSnelheid(int16_t snelheid);
  
      kiesSnelheid(int16_t linkerSnelheid, int16_t rechterSnelheid);
  
   private:
  
      init()
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