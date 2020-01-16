#ifndef SEARCHERS_H
#define SEARCHERS_H

#include "map.h"
#include <cstdlib> //size_t
#include <vector>

enum Directions {
   NORTH,
   EAST,
   SOUTH,
   WEST
};

enum ResearcherStatus {
   RICH,
   LOST,
   DROWNED,
   EXHAUSTED
};

typedef std::vector<int> Searcher;
typedef std::vector<Searcher> SearcherList;

int getSteps(const Searcher& searcher);
int getStatus(const Searcher& searcher);

bool setSteps(Searcher& searcher, int value);
bool setStatus(Searcher& searcher, ResearcherStatus value);

void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher);

#endif //SEARCHERS_H