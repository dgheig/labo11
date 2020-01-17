#ifndef TREASURE_H
#define TREASURE_H

#include "map.h"
#include "searchers.h"

SearcherList runSimulation(const Map& map, size_t startX, size_t startY, int nbSimulation);

void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher);

#endif // TREASURE_H