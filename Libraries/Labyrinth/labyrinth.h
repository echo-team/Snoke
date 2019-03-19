#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "../Common/common.h"
#include <ncurses.h>
#include <string>
#include <cstdio>

/**
 * gameFieldSize - size of a game field(x, y)
 * @type {Point} 
 * @global
 */
extern Point gameFieldSize;


class Labyrinth
{
    private:
        char** labyrinth;
    public:
        void setLabyrinth(Point dimensions);
        void displayLabyrinth();
        void displayUpdated(Point* update[2], int size);
        void updateLabyrinth(Point* update[2], int size);
        bool isFree(Point p);
        bool addPoint(Point p, char style = '*');
        bool remPoint(Point p);
        bool save(std::string name);
};

#endif