#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "../Common/common.h"
#include "../Snake/snake.h"
#include <ncurses.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <list>

#define DISPFULL 0
#define DISPLAB 1
#define DISPUPD 2

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
        std::string reserved = "!";
        int prevDisplayMethod = 0;
        Snake* snake = NULL;
        Point start;
        Point end;
        Point prevStart;
        Point prevEnd;
        void displayLabyrinth();
        void displayUpdated(Point* update[2], int size);
        void updateLabyrinth(Point* update[2], int size);
        void displayFull();
        void sizeHandler();
    public:
        void setLabyrinth(Point dimensions);
        void addSnake(Snake* snake);
        bool addPoint(Point p);
        bool remPoint(Point p);
        void displayHandler(Point* change[2] = NULL, int size = 0);
        bool isFree(Point p);
        bool save(char name[MAXLINE]);
        bool load(char name[MAXLINE]);
};

#endif
