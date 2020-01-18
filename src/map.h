#ifndef MAP_H
#define MAP_H

#include <cstdlib> //size_t
#include <vector>

enum MapState {
    MS_OUT,
    MS_EARTH,
    MS_WATER,
    MS_TREASURE,
    MS_START
};

typedef std::vector<MapState> Axe;
typedef std::vector<Axe> Map;

int getRandomInRange(int max, int min = 0);

size_t getHeight(const Map& map);
size_t getWidth(const Map& map);

Map getEmptyMap(size_t height, size_t width);

MapState getMapValue(const Map& map, size_t x, size_t y);

bool addTreasure(Map& map, size_t height, size_t width);
void addRandomTreasure(Map& map);

bool addLake(Map& map, size_t originX, size_t originY, size_t radius);
void addRandomLake(Map& map);
void addRandomLake(Map& map, size_t maxRadius);

bool addStart(Map& map, size_t x, size_t y);
void addRandomStart(Map& map);
void addRandomStart(Map& map, size_t& x, size_t& y);

Map initWorld(size_t heigth, size_t width, size_t& x, size_t& y);

void displayWorld(const Map& map);
void displayWorld2(const Map& map);

#endif // MAP_H