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

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    size_t startX, startY;
    Map world = initWorld(100, 100, startX, startY);
    displayWorld(world);
    cout << endl;

    WAIT_ENTER;
    return EXIT_SUCCESS;
}
