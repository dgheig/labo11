#ifndef TREASURE_H
#define TREASURE_H

#include <cstdlib>
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


typedef std::vector<MapState> Axe;
typedef std::vector<Axe> Map;

int getRandomInRange(int max, int min = 0);

int getHeight();
int getWidth();

Map getEmptyMap(size_t height, size_t width);

bool addTreasure(Map& map, size_t height, size_t width);
void addRandomTreasure(Map& map);

bool addLake(Map& map, size_t originX, size_t originY, size_t radius);
void addRandomLake(Map& map);

bool addStart(size_t& x, size_t&y)
void addRandomStart(Map& map);

Map initWorld(size_t& x, size_t& y);

void runSimulation(int);

#endif // TREASURE_H