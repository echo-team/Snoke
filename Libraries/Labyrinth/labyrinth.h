#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "../Common/common.h"
#include <ncurses.h>
#include <string>
#include <cstdio>
#include <list>

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
        void addSnake(std::list<Point> snake);
        bool addPoint(Point p);
        bool remPoint(Point p);
        void displayLabyrinth();
        void displayUpdated(Point* update[2], int size);
        void updateLabyrinth(Point* update[2], int size);
        bool isFree(Point p);
        bool save(char name[MAXLINE]);
};

#endif
