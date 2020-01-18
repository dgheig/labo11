#include "searchers.h"
#include "map.h"
#include <vector>
#include <string>
#include <iostream>


std::string ResearcherStatusStringTab[] = {
      "UNDEFINED",
      "RICH",
      "LOST",
      "DROWNED",
      "EXHAUSTED"
};

enum SearcherAttributeIndex {
   SAI_STEPS,
   SAI_STATUS
};

Searcher initSearcher(int stepsValue, ResearcherStatus statusValue) {
   Searcher searcher = {
      stepsValue,
      (int) statusValue
   };
   return searcher;
}

int getSteps(const Searcher& searcher) {
   return searcher[SAI_STEPS];
}

int getStatus(const Searcher& searcher) {
   return searcher[SAI_STATUS];
}

std::string getStatusString(const Searcher& searcher) {
   return ResearcherStatusStringTab[getStatus(searcher)];
}

bool setSteps(Searcher& searcher, int value) {
   searcher[SAI_STEPS] = value;
   return true;
}

bool setStatus(Searcher& searcher, ResearcherStatus value) {
   if (value > EXHAUSTED or value < 0)
      return false;
   searcher[SAI_STATUS] = value;
   return true;
}

bool displaySearcherList(SearcherList& list) {
   if (list.empty())
      return false;

   for (Searcher& searcher : list) {
      std::cout << "Steps : " << getSteps(searcher) << "\tStatus : " << getStatusString(searcher) << std::endl;
   }
   return true;
}