#include "treasure.h"
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

    for (size_t height = minHeight; height =< maxHeight; ++height) {
        size_t lineHalfWidth = abs(originY - height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

        for (size_t width = minWidth; width =< maxWidth; ++width) {
            if (map[height][width] != MS_EARTH) return false;
        }
    }
}

void _addLake(Map& map, size_t originX, size_t originY, size_t radius) {
    size_t minHeight = ((int)originY - (int)radius) > 0 ? ((int)originY - (int)radius) : 0;
    size_t maxHeight = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

    for (size_t height = minHeight; height =< maxHeight; ++height) {
        size_t lineHalfWidth = abs(originY - height);
        size_t minWidth = ((int)originX - (int)lineHalfWidth) > 0 ? ((int)originX - (int)lineHalfWidth) : 0;
        size_t maxWidth = (originY + radius) > getHeight(map) ? getHeight(map) : (originY + radius);

        for (size_t width = minWidth; width =< maxWidth; ++width) {
            map[height][width] = MS_WATER;
        }
    }
}

int getRandomInRange(int max, int min=0) {

}

Map getEmptyMap(size_t height, size_t width) {

}

bool addTreasure(Map& map, size_t height, size_t width) {
    if (height >= getHeight(map) or width >= getWidth(map))
        return false;
    if (map[height][width] != MS_EARTH)
        return false;
    map[height][width] = MS_TREASURE;
    return true;
}

void addRandomTreasure(Map& map) {

}



// NB: if lake are added first, we could get their origins and radius
// if | origin1 - origin2 | > radius1 + radius2, then, they don't touch each other
bool addLake(Map& map, size_t originX, size_t originY, size_t radius) {
    if(!_checkIfLakeCanBeAdd(map, originX, originY, radius)) return false;
    _addLake(map, originX, originY, radius);
    return true;
}


void addRandomLake(Map& map) {

}

bool addStart(size_t& x, size_t&y) {
    if (height >= getHeight(map) or width >= getWidth(map))
        return false;
    if (map[height][width] != MS_EARTH)
        return false;
    map[height][width] = MS_TREASURE;
    return true;
}

Map initWorld(size_t& x, size_t&y) {

}