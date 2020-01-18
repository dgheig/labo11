/*
-----------------------------------------------------------------------------------
Laboratoire : labo_11
Fichier     : utilities.h
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 18.01.2020

But         : Run one or more simulation of treasure hunt.
              The searchers progress randomly through a map.
              Statistics about the simulation are displayed at the end.
Remarque(s) :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef UTILITES_h
#define UTILITES_h

int getRandomInRange(int max, int min = 0);

const char RESTART_CHAR   = 'Y';
const char STOP_CHAR      = 'N';

/*!
 * @return true if the user has entered RESTART_CHAR and false if the user has entered STOP_CHAR
 * @brief This function keeps asking as long as the user enters anything else than RESTART_CHAR or STOP_CHAR
 */
bool askForRestart();

int askForNumberOfSimulation();

#endif // UTILITES_h