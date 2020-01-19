/*
-----------------------------------------------------------------------------------
Laboratory  : labo_11
File        : utilities.h
Author(s)   : Yannick Schaufelberger et David Gallay
Date        : 18.01.2020

Goal        : Library for various utilities
Remark(s)   :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilator  : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef UTILITES_h
#define UTILITES_h

/**
 * @param max
 * @param min
 * @return a random int between min and max, both included
 */
int getRandomInRange(int max, int min = 0);

const char RESTART_CHAR   = 'Y';
const char STOP_CHAR      = 'N';

/**
 * @brief This function keeps asking as long as the user entersanything else than RESTART_CHAR
 * or STOP_CHAR
 * @return true if the user has entered RESTART_CHAR and false if the user has entered STOP_CHAR
 */
bool askForRestart();

/**
 * @brief This function keeps asking as long as the user enters a negative number or a char
 * @return the number entered by the user
 */
int askForNumberOfSimulation();

#endif // UTILITES_h