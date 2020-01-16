#include "searchers.h"
#include "map.h"
#include <cstdlib>
#include <vector>

enum SearcherAttributeIndex {
   SAI_STEPS,
   SAI_STATUS
};

int getSteps(const Searcher& searcher) {
   return searcher[SAI_STEPS];
}

int getStatus(const Searcher& searcher) {
   return searcher[SAI_STATUS];
}

bool setSteps(Searcher& searcher, int value) {
   searcher[SAI_STEPS] = value;
   return true;
}

bool setStatus(Searcher& searcher, ResearcherStatus value) {
   if (value > EXHAUSTED)
      return false;
   searcher[SAI_STATUS] = value;
   return true;
}

void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher) {
   int steps = 0;

   size_t currentX = startX;
   size_t currentY = startY;

   int maxSteps = (int)(getHeight(map) * getWidth(map));

   for (int steps = 0; steps < maxSteps; ++steps) {

      switch ((Directions)getRandomInRange(3)) {
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

      if (getMapValue(map, currentX, currentY) == MS_OUT) {
         setSteps(searcher, steps);
         setStatus(searcher, LOST);
         break;
      } else if (getMapValue(map, currentX, currentY) == MS_WATER) {
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
   }
}