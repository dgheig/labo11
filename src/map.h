/*
-----------------------------------------------------------------------------------
Laboratoire : labo_11
Fichier     : map.h
Auteur(s)   : Yannick Schaufelberger et David Gallay
Date        : 18.01.2020

But         :
Remarque(s) :

                There is the github repository:
                https://github.com/dgheig/labo11

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef MAP_H
#define MAP_H

#include <cstdlib> //size_t
#include <vector>

enum MapState {
    MS_OUT,
    MS_EARTH,
    MS_WATER,
    MS_TREASURE,
    MS_START
};

const int NUMBER_OF_LAKE = 3;

typedef std::vector<MapState> Axe;
typedef std::vector<Axe> Map;

size_t getHeight(const Map& map);
size_t getWidth(const Map& map);

Map getEmptyMap(size_t height, size_t width);

MapState getMapValue(const Map& map, size_t x, size_t y);
bool setMapValue(Map& map, size_t x, size_t y, MapState value);

bool addTreasure(Map& map, size_t height, size_t width);
void addRandomTreasure(Map& map);

bool addLake(Map& map, size_t originX, size_t originY, size_t radius);
void addRandomLake(Map& map);
void addRandomLake(Map& map, size_t maxRadius);

bool addStart(Map& map, size_t x, size_t y);
void addRandomStart(Map& map);
void addRandomStart(Map& map, size_t& x, size_t& y);

Map initWorld(size_t heigth, size_t width, size_t& x, size_t& y);

void displayWorld(const Map& map);

#endif // MAP_H