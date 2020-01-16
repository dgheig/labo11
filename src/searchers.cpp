int getStatus(std::vector<std::vector<int>>& simulationStatus, int id) {
   
}

int getSteps(std::vector<std::vector<int>>& simulationStatus, int id) {
   
}

void setStatus(std::vector<std::vector<int>>& simulationStatus, int id, int value) {
   
}

void setSteps(std::vector<std::vector<int>>& simulationStatus, int id, int value) {
   
}

void runSimulation(const Map& map, size_t startX, size_t startY, std::vector<std::vector<int>>&simulationStatus) {
   int steps = 0;

   size_t currentX = startX;
   size_t currentY = startY;

   do {

      Directions direction = getRandomInRange(3);

      switch (direction) {
         case NORTH:
            currentY++;
            break;
         case EAST:
            currentX++;
            break;
         case SOUTH:
            currentY--;
            break;
         case WEST:
            currentX--;
            break;
      }



      ++steps;

   } while (steps < (getHeight(map) * getWidth(map)));
}