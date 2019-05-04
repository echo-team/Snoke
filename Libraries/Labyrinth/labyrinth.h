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
#define DISPPART 1
/**
 * @brief    the whole labyrinth can fit and was already fully redrawn so we just need to redraw the changed Points
 */
#define DISPUPD 2

/**
* @var Point gameFieldSize
* size of a game field(x, y)
 */
extern Point gameFieldSize;

/**
 * @class Labyrinth labyrinth.h
 * @brief   class for containing and displaying the game field
 * @prop    labyrinth           - game field, consisting of chars
 * @prop    reserved            - array of reserved chars for inside usage
 * @prop    prevDisplayMethod   - value, containing the makr of which display method was previously called(is used in displaying)
 * @prop    snake               - pointer to a local_player's snake
 * @prop    start               - top left corner from which the drawing of the current cycle starts
 * @prop    end                 - bottom right corner at which the drawing of the current cycle ends
 * @prop    prevStart           - previous value of start
 * @prop    prevEnd             - previous value of end
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
        void displayPartialy();
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
