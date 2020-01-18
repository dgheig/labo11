#include "map.h"
#include <cstdlib>
#include <iostream>
#include <ctime> //time()

using namespace std;

// bool _addWater(Map& map, size_t height, size_t width);
bool _checkIfLakeCanBeAdd(Map& map, size_t originX, size_t originY, size_t radius);
void _addLake(Map& map, size_t originX, size_t originY, size_t radius);

// bool _addWater(Map& map, size_t height, size_t width) {
//     if (height >= getHeight(map) or width >= getWidth(map)) return true;
//     if (map[height][width] != MS_EARTH) return false;
//     map[height][width] = MS_WATER;
//     return true;
// }

bool _checkIfLakeCanBeAdd(Map& map, size_t originX, size_t originY, size_t radius) {
    size_t mapHeight = getHeight(map) - 1;
    size_t mapWidth  = getWidth(map) - 1;

    size_t minHeight = ((int)originY - (int)radius) > 0 ? ((int)originY - (int)radius) : 0;
    size_t maxHeight = (originY + radius) > mapHeight ? mapHeight : (originY + radius);


    for (size_t height = minHeight; height <= maxHeight; ++height) {
        size_t lineHalfWidth = radius - abs((int)originY - (int)height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originX + lineHalfWidth) > mapWidth ? mapWidth : (originX + lineHalfWidth);

        for (size_t width = minWidth; width <= maxWidth; ++width) {
            // cerr << height << '-' << width << endl;
            if (map[height][width] != MS_EARTH) return false;
        }
    }
    return true;
}

void _addLake(Map& map, size_t originX, size_t originY, size_t radius) {
    size_t mapHeight = getHeight(map) - 1;
    size_t mapWidth  = getWidth(map) - 1;

    size_t minHeight = ((int)originY - (int)radius) > 0 ? ((int)originY - (int)radius) : 0;
    size_t maxHeight = (originY + radius) > mapHeight ? mapHeight : (originY + radius);

    for (size_t height = minHeight; height <= maxHeight; ++height) {
        size_t lineHalfWidth = radius - abs((int)originY - (int)height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originX + lineHalfWidth) > mapWidth ? mapWidth : (originX + lineHalfWidth);

        for (size_t width = minWidth; width <= maxWidth; ++width) {
            map[height][width] = MS_WATER;
        }
    }
}

size_t getHeight(const Map& map) {
   return map.size();
}

size_t getWidth(const Map& map) {
   if (map.empty()) return 0;
   return map[0].size();
}

Map getEmptyMap(size_t height, size_t width) {
   return Map(height, Axe(width, MS_EARTH));
}

MapState getMapValue(const Map& map, size_t x, size_t y) {
   if (y >= getHeight(map) or x >= getWidth(map))
      return MS_OUT;
   return map[y][x];
}

bool addTreasure(Map& map, size_t x, size_t y) {
    if (y >= getHeight(map) or x >= getWidth(map))
        return false;
    if (map[y][x] != MS_EARTH)
        return false;
    map[y][x] = MS_TREASURE;
    return true;
}

void addRandomTreasure(Map& map) {
    size_t x;
    size_t y;
    do {
        x = getRandomInRange(getHeight(map));
        y = getRandomInRange(getWidth(map));
    } while (!addTreasure(map, x, y));
}

// NB: if lake are added first, we could get their origins and radius
// if | origin1 - origin2 | > radius1 + radius2, then, they don't touch each other

bool addLake(Map& map, size_t originX, size_t originY, size_t radius) {
   if (!_checkIfLakeCanBeAdd(map, originX, originY, radius)) return false;
   _addLake(map, originX, originY, radius);
   return true;
}

void addRandomLake(Map& map) {
    int maxRadius = (getHeight(map) > getWidth(map) ? getWidth(map) : getHeight(map)) / 3;
    addRandomLake(map, maxRadius);
}

void addRandomLake(Map& map, size_t maxRadius) {
    size_t radius;
    size_t height;
    size_t width;
    do {
        radius = getRandomInRange(maxRadius);
        height = getRandomInRange(getHeight(map));
        width = getRandomInRange(getWidth(map));
        #ifdef DEBUG
        cout << "addRandomLake called" << endl;
        cout << "maxRadius: " << maxRadius << endl;
        cout << "radius: " << radius << endl;
        cout << "height: " << height << endl;
        cout << "width: " << width << endl;
        #endif
    } while (!addLake(map, height, width, radius));
}

bool addStart(Map& map, size_t x, size_t y) {
    if (x >= getHeight(map) or y >= getWidth(map))
        return false;
    if (map[x][y] != MS_EARTH)
        return false;
    map[x][y] = MS_START;
    return true;
}

void addRandomStart(Map& map) {
    size_t x;
    size_t y;
    do {
        x = getRandomInRange(getHeight(map));
        y = getRandomInRange(getWidth(map));
    } while (!addStart(map, x, y));
}

void addRandomStart(Map& map, size_t& x, size_t& y) {
    do {
        x = getRandomInRange(getHeight(map));
        y = getRandomInRange(getWidth(map));
    } while (!addStart(map, x, y));
}

Map initWorld(size_t heigth, size_t width, size_t& x, size_t& y) {
   const int NUMBER_OF_LAKE = 3;

   Map map = getEmptyMap(heigth, width);

   for (int i = 0; i < NUMBER_OF_LAKE; ++i) {
      addRandomLake(map);
   }
   addRandomTreasure(map);
   addRandomStart(map, x, y);

   return map;
}


void displayWorld(const Map& map) {
    for(const auto& axe : map) {
        for(const auto state: axe) {
        #ifdef _WIN32
            switch (state)
            {
            case MS_TREASURE:
                cout << "T";
                break;

            case MS_WATER:
                cout << "W";
                break;

            case MS_START:
                cout << "S";
                break;

            case MS_EARTH:
            default:
                cout << " ";
                break;
            }
        }
        #else
            switch (state)
            {
            case MS_TREASURE:
                cout << "\e[30;43m \e[0m";
                break;

            case MS_WATER:
                cout << "\e[30;44m \e[0m";
                break;

            case MS_START:
                cout << "\e[30;41m \e[0m";
                break;

            case MS_EARTH:
            default:
                cout << "\e[30;42m \e[0m";
                break;
            }
        }
        #endif
        cout << endl;
    }
}

// void runSimulation(const Map& map, size_t startX, size_t startY, std::vector<std::vector<int>>&simulationStatus) {
//    int steps = 0;

//    size_t currentX = startX;
//    size_t currentY = startY;

//    do {

//       Directions direction = getRandomInRange(3);

//       switch (direction) {
//          case NORTH:
//             currentY++;
//             break;
//          case EAST:
//             currentX++;
//             break;
//          case SOUTH:
//             currentY--;
//             break;
//          case WEST:
//             currentX--;
//             break;
//       }



//       ++steps;

//    } while (steps < (getHeight(map) * getWidth(map)));
// }