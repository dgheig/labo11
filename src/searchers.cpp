#include "searchers.h"
#include "map.h"
#include <cstdlib>
#include <vector>

int getStatus(const std::vector<std::vector<int>>&searcherStatus, int id) {
   
}

int getSteps(const std::vector<std::vector<int>>&searcherStatus, int id) {
   
}

void setStatus(std::vector<std::vector<int>>&searcherStatus, int id, int value) {
   
}

void setSteps(std::vector<std::vector<int>>&searcherStatus, int id, int value) {
   
}

void runSearcher(const Map& map, size_t startX, size_t startY, std::vector<std::vector<int>>&searcherStatus, int idSearcher) {
   int steps = 0;

   size_t currentX = startX;
   size_t currentY = startY;
   
   int maxSteps = (int)getHeight(map) * (int)getWidth(map);

   do {

      Directions direction = (Directions)getRandomInRange(3);

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

      if (currentX < 0 || currentX > getWidth() ||
          currentY < 0 || currentY > getHeight()) {
         setStatus(searcherStatus, idSearcher, (int)LOST);
         setSteps(searcherStatus, idSearcher, steps);
         break;
      }

      if (getMapValue(currentX, currentY) == MS_WATER) {
         setStatus(searcherStatus, idSearcher, (int)DROWNED);
         setSteps(searcherStatus, idSearcher, steps);
         break;
      } else if (getMapValue(currentX, currentY) == MS_TREASURE) {
         setStatus(searcherStatus, idSearcher, (int)RICH);
         setSteps(searcherStatus, idSearcher, steps);
         break;
      }
      
      if (steps == maxSteps) {
         setStatus(searcherStatus, idSearcher, (int)EXHAUSTED);
         setSteps(searcherStatus, idSearcher, steps);
         break;
      }

   } while (steps < maxSteps);
}