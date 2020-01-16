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

void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher) {
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

      if (currentX > getWidth(map) or currentY > getHeight(map)) {
         setSteps(searcher, steps);
         setStatus(searcher, LOST);
         break;
      }

      if (getMapValue(map, currentX, currentY) == MS_WATER) {
         setSteps(searcher, steps);
         setStatus(searcher, DROWNED);
         break;
      } else if (getMapValue(map, currentX, currentY) == MS_TREASURE) {
         setSteps(searcher, steps);
         setStatus(searcher, RICH);
         break;
      }
      
      if (steps == maxSteps) {
         setSteps(searcher, steps);
         setStatus(searcher, EXHAUSTED);
         break;
      }

   } while (steps < maxSteps);
}