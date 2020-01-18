#include "utilities.h"
#include <ctime> //time()
#include <cstdlib> // srand()
#include <iostream>
#include <limits>

using namespace std;
#define CLEAR_BUFFER cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')

int getRandomInRange(int max, int min) {
   static bool firstTime = true;
   if (firstTime) {
      srand(time(NULL));
      firstTime = false;
   }

   return rand() % (max - min + 1) + min;
}

bool askForRestart() {
   while(true) {
      cout << "Do you want to restart? ["
           << RESTART_CHAR << "/" << STOP_CHAR
           << "]" << endl;
      char c = (char) getchar();
      CLEAR_BUFFER;
      if ( c == RESTART_CHAR) return true;
      else if ( c == STOP_CHAR) return false;
   }
}

int askForNumberOfSimulation() {
   int simulationNumber;
   do {
      cout << "How many simulation do you want? (must be positiv): ";
      cin >> simulationNumber;
      cout << endl;

      if (cin.fail()) {
         cin.clear();
         simulationNumber = -1;
      }

      CLEAR_BUFFER;
   } while(simulationNumber <= 0);

   return simulationNumber;
}
