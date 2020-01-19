/*
-----------------------------------------------------------------------------------
Laboratory  : labo_11
File        : labo_11_schaufelberger_yannick_gallay_david.cpp
Author(s)   : Yannick Schaufelberger and David Gallay
Date        : 18.01.2020

Goal        : Run one or more simulation of treasure hunt.
              The searchers progress randomly through a map.
              Statistics about the simulation are displayed at the end.
Remark(s)   :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilator  : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/treasure.h"
#include "src/utilities.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {

    do {
        size_t startX, startY;
        Map world = initWorld(50, 50, startX, startY);
        displayWorld(world);
        cout << endl;

        size_t simulationNumber = (size_t)askForNumberOfSimulation();
        SearcherList list = runSimulation(world, startX, startY, simulationNumber);
        displaySearcherList(list);

        double probability = 0, avgSteps = 0.0;
        if(getStatistics(list, probability, avgSteps))
            cout << "probability : " << probability << "\tavgSteps : " << avgSteps << endl;
        else
            cerr << "Sorry, we couldn't afford to get the simulations statistics";


    } while (askForRestart());

    std::cout << "Press <ENTER> to quit the program" << std::endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
