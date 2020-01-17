#ifndef SEARCHERS_H
#define SEARCHERS_H

#include "map.h"
#include <cstdlib> //size_t
#include <vector>

enum ResearcherStatus {
   UNDEFINED,
   RICH,
   LOST,
   DROWNED,
   EXHAUSTED
};

typedef std::vector<int> Searcher;
typedef std::vector<Searcher> SearcherList;

Searcher initSearcher(int stepsValue = 0, ResearcherStatus statusValue = UNDEFINED);

int getSteps(const Searcher& searcher);
int getStatus(const Searcher& searcher);

bool setSteps(Searcher& searcher, int value);
bool setStatus(Searcher& searcher, ResearcherStatus value);

bool displayList(SearcherList& list);

#endif //SEARCHERS_H