#include "treasure.h"
#include <cstdlib>
#include <ctime> //time()

using namespace std;

// bool _addWater(Map& map, size_t height, size_t width);
bool _checkIfLakeCanBeAdd(Map& map, size_t originX, size_t originY, size_t radius);
void _addLake(Map& map, size_t originX, size_t originY, size_t radius);

// bool _addWater(Map& map, size_t height, size_t width) {
//     if (height >= getHeight(map) or width >= getWidth(map)) return true;
//     if (map[height][width] != MS_EARTH) return false;
//     map[height][width] = MS_WATER;
//     return true;
// }

bool _checkIfLakeCanBeAdd(Map& map, size_t originX, size_t originY, size_t radius) {
   size_t minHeight = ((int) originY - (int) radius) > 0 ? ((int) originY - (int) radius) : 0;
   size_t maxHeight = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

   for (size_t height = minHeight; height = < maxHeight; ++height) {
      size_t lineHalfWidth = abs(originY - height);
      size_t minWidth = ((int) originX - (int) lineHalfWidth) > 0 ? ((int) originX - (int) lineHalfWidth) : 0;
      size_t maxWidth = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

      for (size_t width = minWidth; width = < maxWidth; ++width) {
         if (map[height][width] != MS_EARTH) return false;
      }
   }
}

void _addLake(Map& map, size_t originX, size_t originY, size_t radius) {
   size_t minHeight = ((int) originY - (int) radius) > 0 ? ((int) originY - (int) radius) : 0;
   size_t maxHeight = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

   for (size_t height = minHeight; height = < maxHeight; ++height) {
      size_t lineHalfWidth = abs(originY - height);
      size_t minWidth = ((int) originX - (int) lineHalfWidth) > 0 ? ((int) originX - (int) lineHalfWidth) : 0;
      size_t maxWidth = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

      for (size_t width = minWidth; width = < maxWidth; ++width) {
         map[height][width] = MS_WATER;
      }
   }
}

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

int getHeight(Map& map) {
   return map.size();
}

int getWidth(Map& map) {
   if (getHeight(map) == 0) return 0;
   return map[0].size();
}

Map getEmptyMap(size_t height, size_t width) {
   return Map(height, Axe(width, MS_EARTH));
}

bool addTreasure(Map& map, size_t height, size_t width) {
   if (height >= getHeight(map) or width >= getWidth(map))
      return false;
   if (map[height][width] != MS_EARTH)
      return false;
   map[height][width] = MS_TREASURE;
   return true;
}

void addRandomTreasure(Map& map) {

}



// NB: if lake are added first, we could get their origins and radius
// if | origin1 - origin2 | > radius1 + radius2, then, they don't touch each other

bool addLake(Map& map, size_t originX, size_t originY, size_t radius) {
   if (!_checkIfLakeCanBeAdd(map, originX, originY, radius)) return false;
   _addLake(map, originX, originY, radius);
   return true;
}

void addRandomLake(Map& map) {

}

bool addStart(size_t& x, size_t&y) {
   if (height >= getHeight(map) or width >= getWidth(map))
      return false;
   if (map[height][width] != MS_EARTH)
      return false;
   map[height][width] = MS_TREASURE;
   return true;
}

Map initWorld(size_t& x, size_t& y) {
   const int numberOfLake = 3;

   Map map = getEmptyMap(y, x);

   for (int i = 0; i < numberOfLake; ++i) {
      addRandomLake(map);
   }
   addRandomTreasure(map);
   addRandomStart(map);

   return map;
}

void runSimulation(Map map, size_t startX, size_t startY, std::vector<std::vector<int>>&simulationStatus) {
   int steps = 0;

   size_t currentX = startX;
   size_t currentY = startY;

   do {

      Directions direction = getRandomInRange(3);

      switch (direction) {
         case NORTH:
            currentY++;
            break;
         case EAST:
            currentX++;
            break;
         case SOUTH:
            currentY--;
            break;
         case WEST:
            currentX--;
            break;
      }

      
      
      ++steps;

   } while (steps < (getHeight(map) * getWidth(map)));
}