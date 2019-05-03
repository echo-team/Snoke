/**
 * @file labyrinth.h
 * @author Yegor Ignatov
 * @brief Definitions and prototypes for Labyrinth class
 * @version 0.1
 * @date 2019-05-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
 * @brief    the whole labyrinth can fit and was redrawed
 */
#define DISPFULL 0
/**
 * @brief    the whole labyrinth doesn't fit, so we are displaying it partialy
 */
#define DISPLAB 1
/**
 * @brief    the whole labyrinth can fit and was already fully redrawn so we just need to redraw the changed Points
 */
#define DISPUPD 2

/**
 * gameFieldSize - size of a game field(x, y)
 * @type {Point}
 * @global
 */
extern Point gameFieldSize;

/**
 * @class Labyrinth labyrinth.h
 * @brief   class for containing and displaying the game field
 */
class Labyrinth
{
    private:
        /**
         * @prop    char**          labyrinth
         * @brief   game field, consisting of chars
         */
        char** labyrinth;
        /**
         * @prop    std::string     reserved
         * @brief   rray of reserved chars for inside usage
         */
        std::string reserved = "!";
        /**
         * @prop    int             prevDisplayMethod
         * @brief   value, containing the makr of which display method was previously called(is used in displaying)
         */
        int prevDisplayMethod = 0;
        /**
         * @prop    Snake*          snake
         * @brief    pointer to a local_player's snake
         */
        Snake* snake = NULL;
        /**
         * @prop    Point           start
         * @brief    top left corner from which the drawing of the current cycle starts
         */
        Point start;
        /**
         * @prop    Point           end
         * @brief    bottom right corner at which the drawing of the current cycle ends
         */
        Point end;
        /**
         * @prop    Point           prevStart
         * @brief   previous value of start
         */
        Point prevStart;
        /**
         * @prop    Point           prevEnd
         * @brief   previous value of end
         */
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
