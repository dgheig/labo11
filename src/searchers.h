/*
-----------------------------------------------------------------------------------
Laboratory  : labo_11
File        : searchers.h
Author(s)   : Yannick Schaufelberger et David Gallay
Date        : 18.01.2020

Goal        : Library defining the Searchers and functions to modify, get values or
              display a SearchersList
Remark(s)   :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilator  : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef SEARCHERS_H
#define SEARCHERS_H

#include "map.h"
#include <cstdlib> //size_t
#include <vector>
#include <string>

enum ResearcherStatus {
   UNDEFINED,
   RICH,
   LOST,
   DROWNED,
   EXHAUSTED
};

typedef std::vector<int> Searcher;
typedef std::vector<Searcher> SearcherList;

/**
 * @param stepsValue
 * @param statusValue
 * @return a searcher initialized with the given values
 */
Searcher initSearcher(int stepsValue = 0, ResearcherStatus statusValue = UNDEFINED);

/**
 * @param searcher
 * @return the amount of steps taken by a searcher
 */
int getSteps(const Searcher& searcher);
/**
 * @param searcher
 * @return the status of a searcher
 */
int getStatus(const Searcher& searcher);
/**
 * @param searcher
 * @return a string containing the status of a searcher
 */
std::string getStatusString(const Searcher& searcher);

/**
 * @brief sets the steps of a searcher to the given value
 * @param searcher
 * @param value
 * @return true if success
 */
bool setSteps(Searcher& searcher, int value);
/**
 * @brief sets the status of a searcher to the given value
 * @param searcher
 * @param value
 * @return true if success, false if not
 */
bool setStatus(Searcher& searcher, ResearcherStatus value);

/**
 * @brief displays the information of every searcher in the list
 * @param list
 * @return true if success, false if not
 */
bool displaySearcherList(SearcherList& list);

#endif //SEARCHERS_H