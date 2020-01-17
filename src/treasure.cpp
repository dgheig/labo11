#include "treasure.h"
#include "map.h"

using namespace std;

enum Directions {
   NORTH,
   EAST,
   SOUTH,
   WEST
};

SearcherList runSimulation(const Map& map, size_t startX, size_t startY, int nbSimulation) {
   SearcherList searcherList(nbSimulation);
   Searcher searcher;
   
   for (int i = 0; i < nbSimulation; ++i) {
      searcher = initSearcher();
      runSearcher(map, startX, startY, searcher);
      searcherList[i] = searcher;
   }
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