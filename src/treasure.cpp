#include "treasure.h"
#include <cstdlib>
#include <ctime> //time()

using namespace std;

int getRandomInRange(int max, int min) {
   static bool firstTime = true;
   if (firstTime) {
      srand(time(NULL));
      firstTime = false;
   }

   if (min < max) {
      return rand() % (max - min + 1) + min;
   } else {
      return rand() % (min - max + 1) + max;
   }
}

int getHeight() {
   return 100;
}

int getWidth() {
   return 200;
}

Map getEmptyMap(size_t height, size_t width) {
   return Map(height, Axe(width, MS_EARTH));
}

bool addTreasure(Map& map, size_t height, size_t width) {

}

void addRandomTreasure(Map& map) {

}

void addLake(Map& map, size_t originX, size_t originY, size_t radius) {

}

void addRandomLake(Map& map) {

}

bool addStart(size_t& x, size_t&y) {

}

Map initWorld(size_t& x, size_t&y) {
   const int numberOfLake = 3;

   Map world = getEmptyMap(getHeight(), getWidth());

   for (int i = 0; i < numberOfLake; ++i) {
      addRandomLake(world);
   }
   addRandomTreasure(world);
   addRandomStart(world);
   
   return world;
}