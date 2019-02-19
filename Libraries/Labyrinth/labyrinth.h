#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "../Common/common.h"
#include <ncurses.h>


/**
 * gameFieldSize - size of a game field(x, y)
 * @type {Point} 
 * @global
 */
extern Point gameFieldSize;


class Labyrinth
{
    private:
        bool** labyrinth;
    public:
        void setLabyrinth(Point dimensions);
        void displayLabyrinth();
        void displayUpdated(Point* update[2], int size);
        void updateLabyrinth(Point* update[2], int size);
        bool isFree(Point p);
        bool addPoint(Point p);
        bool remPoint(Point p);
};

#endif