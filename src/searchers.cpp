#include "searchers.h"
#include "map.h"
#include <cstdlib>
#include <vector>

int getSteps(const Searcher& searcher) {
   return searcher[0];
}

int getStatus(const Searcher& searcher) {
   return searcher[1];
}

bool setSteps(Searcher& searcher, int value) {
   searcher[0] = value;
   return true;
}

bool setStatus(Searcher& searcher, ResearcherStatus value) {
   if (value > EXHAUSTED)
      return false;
   searcher[1] = value;
   return true;
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
         setSteps(searcherStatus, idSearcher, steps);
         setStatus(searcherStatus, idSearcher, LOST);
         break;
      }

      if (getMapValue(currentX, currentY) == MS_WATER) {
         setSteps(searcherStatus, idSearcher, steps);
         setStatus(searcherStatus, idSearcher, DROWNED);
         break;
      } else if (getMapValue(currentX, currentY) == MS_TREASURE) {
         setSteps(searcherStatus, idSearcher, steps);
         setStatus(searcherStatus, idSearcher, RICH);
         break;
      }
      
      if (steps == maxSteps) {
         setSteps(searcherStatus, idSearcher, steps);
         setStatus(searcherStatus, idSearcher, EXHAUSTED);
         break;
      }

   } while (steps < maxSteps);
}