#include "treasure.h"
#include "map.h"
// #include "treasure.h"

using namespace std;

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