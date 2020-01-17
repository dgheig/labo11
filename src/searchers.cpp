#include "searchers.h"
#include "map.h"
#include <cstdlib>
#include <vector>

enum SearcherAttributeIndex {
   SAI_STEPS,
   SAI_STATUS
};

Searcher initSearcher(int stepsValue, ResearcherStatus statusValue) {
   Searcher searcher = {stepsValue, (int) statusValue};
   return searcher;
}

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