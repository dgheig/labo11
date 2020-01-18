#include "utilities.h"
#include <ctime> //time()
#include <cstdlib> // srand()

int getRandomInRange(int max, int min) {
   static bool firstTime = true;
   if (firstTime) {
      srand(time(NULL));
      firstTime = false;
   }

   return rand() % (max - min + 1) + min;
}