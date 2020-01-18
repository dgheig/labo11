#ifndef TREASURE_H
#define TREASURE_H

#include "map.h"
#include "searchers.h"

/**
 * @brief Simulates nbSimulation searchers starting at the coordinates startX and startY
 * on the map
 * @param map
 * @param startX
 * @param startY
 * @param nbSimulation
 * @return a list containing the status and steps of every simulated searcher
 */
SearcherList runSimulation(const Map& map, size_t startX, size_t startY, int nbSimulation);

/**
 * @brief walks a searcher on the map, defines the status and steps taken at the end.
 * @param map
 * @param startX
 * @param startY
 * @param searcher
 */
void runSearcher(const Map& map, size_t startX, size_t startY, Searcher& searcher);

/**
 * @brief calculates the probability for a searcher to find the treasure, and the
 * average steps taken to find it
 * @param list
 * @param probability
 * @param avgSteps
 * @return 
 */
bool getStatistics(const SearcherList& list, double& probability, double& avgSteps);

#endif // TREASURE_H