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