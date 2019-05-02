#ifndef LABYRINTH_H
#define LABYRINTH_H
#include "../Common/common.h"
#include "../Snake/snake.h"
#include <ncurses.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <list>

/**
 * @const {int} DISPFULL - the whole labyrinth can fit and was redrawed
 * @const {int} DISPLAB - the whole labyrinth doesn't fit, so we are displaying it partialy
 * @const {int} DISPUPD - the whole labyrinth can fit and was already fully redrawn so we just need to redraw the changed Points
 */
#define DISPFULL 0
#define DISPLAB 1
#define DISPUPD 2

/**
 * gameFieldSize - size of a game field(x, y)
 * @type {Point}
 * @global
 */
extern Point gameFieldSize;

/**
 * @brief   class for containing and displaying the game field
 * @prop    labyrinth         - game field, consisting of chars
 * @prop    reserved          - array of reserved chars for inside usage
 * @prop    prevDisplayMethod - value, containing the makr of which display method was previously called(is used in displaying)
 * @prop    snake             - a pointer to a local_player's snake
 * @prop    start             - a top left corner from which the drawing of the current cycle starts
 * @prop    end               - a bottom right corner at which the drawing of the current cycle ends
 */
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
