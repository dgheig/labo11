#include "treasure.h"
#include "map.h"
#include "searchers.h"
#include <algorithm>

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
   
   return searcherList;
}

void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher) {
   size_t currentX = startX;
   size_t currentY = startY;

   int maxSteps = (int)(getHeight(map) * getWidth(map));

   for (int steps = 0; steps <= maxSteps; ++steps) {
      if (getStatus(searcher) != UNDEFINED) {
         setSteps(searcher, steps);
         break;
      }
      if (steps == maxSteps) {
         setSteps(searcher, steps);
         setStatus(searcher, EXHAUSTED);
         break;
      }

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

      switch (getMapValue(map, currentX, currentY)) {
         case MS_OUT:
            setStatus(searcher, LOST);
            break;
         case MS_WATER:
            setStatus(searcher, DROWNED);
            break;
         case MS_TREASURE:
            setStatus(searcher, RICH);
            break;
      }
   }
}

bool IsRich(const Searcher& searcher) {
   return (getStatus(searcher) == RICH);
}

void getStatistics(const SearcherList& list, double& probability, double& avgSteps) {
   probability = (double) std::count_if(list.begin(), list.end(), IsRich) / (double)list.size();

   int sum = 0, counter = 0;
   for (const Searcher& searcher : list) {
      if (getStatus(searcher) == RICH) {
         sum += getSteps(searcher);
         ++counter;
      }
   }
   avgSteps = (double)sum / (double)counter;
}