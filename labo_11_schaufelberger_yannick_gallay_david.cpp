/*
-----------------------------------------------------------------------------------
Laboratoire : labo_11
Fichier     : labo_11_schaufelberger_yannick_gallay_david.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        :

But         :
Remarque(s) :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
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
