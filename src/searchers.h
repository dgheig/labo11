#ifndef SEARCHERS_H
#define SEARCHERS_H

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

typedef std::vector<MapState> Axe;
typedef std::vector<Axe> Map;

int getStatus(std::vector<std::vector<int>>& simulationStatus, int id);
int getSteps(std::vector<std::vector<int>>& simulationStatus, int id);

void setStatus(std::vector<std::vector<int>>& simulationStatus, int id, int value);
void setSteps(std::vector<std::vector<int>>& simulationStatus, int id, int value);

void runSimulation(const Map& map, size_t startX, size_t startY, std::vector<std::vector<int>>& simulationStatus);

#endif //SEARCHERS_H