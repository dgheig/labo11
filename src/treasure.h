#ifndef TREASURE_H
#define TREASURE_H

#include <cstdlib> //size_t
#include <vector>

enum MapState {
    MS_EARTH,
    MS_WATER,
    MS_TREASURE,
    MS_START
};

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

int getRandomInRange(int max, int min = 0);

int getHeight(Map& map);
int getWidth(Map& map);

Map getEmptyMap(size_t height, size_t width);

bool addTreasure(Map& map, size_t height, size_t width);
void addRandomTreasure(Map& map);

bool addLake(Map& map, size_t originX, size_t originY, size_t radius);
void addRandomLake(Map& map);

bool addStart(Map& map, size_t x, size_t y);
void addRandomStart(Map& map);

Map initWorld(size_t heigth, size_t width, size_t& x, size_t& y);

void displayWorld(const Map& map);
void displayWorld2(const Map& map);
void runSimulation(Map map, size_t startX, size_t startY, std::vector<std::vector<int>>& simulationStatus);

#endif // TREASURE_H