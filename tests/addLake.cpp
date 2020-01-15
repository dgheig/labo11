/*
-----------------------------------------------------------------------------------
Laboratoire : labo_11
Fichier     : model.cpp
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 25.11.2019

But         : Example of test file for a function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include "../src/treasure.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main() {

    Map map = getEmptyMap(50, 50);
    displayWorld(map);
    cout << endl;

    addLake(map, 25, 25, 5);
    displayWorld(map);
    cout << endl;

    addLake(map, 40, 40, 5);
    displayWorld(map);
    cout << endl;

    addLake(map, 20, 45, 8);
    displayWorld(map);
    cout << endl;

    addLake(map, 49, 49, 10);
    displayWorld(map);
    cout << endl;

    return EXIT_SUCCESS;
}
