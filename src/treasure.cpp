#include "treasure.h"
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
    size_t minHeight = ((int)originY - (int)radius) > 0 ? ((int)originY - (int)radius) : 0;
    size_t maxHeight = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

    // cout << "minHeight: " << minHeight << endl;
    // cout << "maxHeight: " << maxHeight << endl;
    for (size_t height = minHeight; height <= maxHeight; ++height) {
        size_t lineHalfWidth = radius - abs((int)originY - (int)height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originX + lineHalfWidth) > getWidth(map) ? getWidth(map) : (originX + lineHalfWidth);

        // cout << "lineHalfWidth: " << lineHalfWidth << endl;
        // cout << "minWidth: " << minWidth << endl;
        // cout << "maxWidth: " << maxWidth << endl;
        for (size_t width = minWidth; width <= maxWidth; ++width) {
            if (map[height][width] != MS_EARTH) return false;
        }
    }
    return true;
}

void _addLake(Map& map, size_t originX, size_t originY, size_t radius) {
    size_t minHeight = ((int)originY - (int)radius) > 0 ? ((int)originY - (int)radius) : 0;
    size_t maxHeight = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

    // cout << "minHeight: " << minHeight << endl;
    // cout << "maxHeight: " << maxHeight << endl;
    for (size_t height = minHeight; height <= maxHeight; ++height) {
        size_t lineHalfWidth = radius - abs((int)originY - (int)height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originX + lineHalfWidth) > getWidth(map) ? getWidth(map) : (originX + lineHalfWidth);

        // cout << "lineHalfWidth: " << lineHalfWidth << endl;
        // cout << "minWidth: " << minWidth << endl;
        // cout << "maxWidth: " << maxWidth << endl;
        for (size_t width = minWidth; width <= maxWidth; ++width) {
            map[height][width] = MS_WATER;
        }
    }
}


int getRandomInRange(int max, int min) {
   static bool firstTime = true;
   if (firstTime) {
      srand(time(NULL));
      firstTime = false;
   }

   if (min < max) {
      return rand() % (max - min + 1) + min;
   } else {
      return rand() % (min - max + 1) + max;
   }
}

int getHeight(Map& map) {
   return map.size();
}

int getWidth(Map& map) {
   if(getHeight(map) == 0) return 0;
   return map[0].size();
}

Map getEmptyMap(size_t height, size_t width) {
   return Map(height, Axe(width, MS_EARTH));
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
    } while (addTreasure(map, x, y));
}

// NB: if lake are added first, we could get their origins and radius
// if | origin1 - origin2 | > radius1 + radius2, then, they don't touch each other
bool addLake(Map& map, size_t originX, size_t originY, size_t radius) {
    if(!_checkIfLakeCanBeAdd(map, originX, originY, radius)) return false;
    _addLake(map, originX, originY, radius);
    return true;
}

void addRandomLake(Map& map) {

    int maxRadius = (getHeight(map) > getWidth(map) ? getWidth(map) : getHeight(map)) / 3;
    size_t radius;
    size_t height;
    size_t width;
    do {
        radius = getRandomInRange(maxRadius);
        height = getRandomInRange(getHeight(map));
        width = getRandomInRange(getWidth(map));
        cout << "addRandomLake called" << endl;
        cout << "radius: " << radius << endl;
        cout << "height: " << radius << endl;
        cout << "width: " << radius << endl;
    } while (addLake(map, height, width, radius));
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
    } while (addStart(map, x, y));
}

Map initWorld(size_t heigth, size_t width, size_t& x, size_t& y) {
   const int numberOfLake = 3;

   Map map = getEmptyMap(heigth, width);

   for (int i = 0; i < numberOfLake; ++i) {
      addRandomLake(map);
   }
   addRandomTreasure(map);
   addRandomStart(map);

   return map;
}


void displayWorld(const Map& map) {
    for(const auto& axe : map) {
        for(const auto state: axe) {
            switch (state)
            {
            case MS_TREASURE:
                cout << (char)27 << "[30;43m " << (char)27 << "[0m";
                break;

            case MS_WATER:
                cout << (char)27 << "[30;44m " << (char)27 << "[0m";
                break;

            case MS_START:
                cout << (char)27 << "[30;41m " << (char)27 << "[0m";
                break;

            case MS_EARTH:
            default:
                cout << (char)27 << "[30;42m " << (char)27 << "[0m";
                break;
            }
        }
        cout << endl;
    }
}

void displayWorld2(const Map& map) {
    for(const auto& axe : map) {
        for(const auto state: axe) {
            switch (state)
            {
            case MS_TREASURE:
                cout << 'O';
                break;

            case MS_WATER:
                cout << 'W';
                break;

            case MS_START:
                cout << 'Y';
                break;

            case MS_EARTH:
            default:
                cout << 'x';
                break;
            }
        }
        cout << endl;
    }
}

void runSimulation(Map map, size_t startX, size_t startY, std::vector<std::vector<int>>& simulationStatus) {
   int steps = 0;

   do {

   } while (steps < (getHeight(map) * getWidth(map)));
}