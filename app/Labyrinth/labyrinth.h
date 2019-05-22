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
#include "change.h"
#include "../Ball/ball.h"
#include <ncurses.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <list>

/**
 * @class DisplayHandler displayHandler.h
 * @method displayFull
 */
class DisplayHandler
{
    public:
        Labyrinth* labyrinth;
        int prevDisplayMethod = 0;
        void displayHandler(int displayMethod);
        void displayFull();
        void freeDisplay();
        void forcedDisplay(int displayMethod);
        void displayPartialy();
        void displayUpdated();
};


/**
 * @brief    the whole labyrinth can fit and was redrawed
 */
const int DISPFULL = 0;
/**
 * @brief    the whole labyrinth doesn't fit, so we are displaying it partialy
 */
const int DISPPART = 1;
/**
 * @brief    the whole labyrinth can fit and was already fully redrawn so we just need to redraw the changed Points
 */
const int DISPUPD = 2;

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
        Snake* snake = NULL;
        Point start;
        Point end;
        Point prevStart;
        Point prevEnd;
        Point gameFieldSize;
        friend class DisplayHandler;
        DisplayHandler dispHandler;
        void updateLabyrinth();
        void sizeHandler();
    public:
        Change change;
        Ball ball;
        bool setLabyrinth(Point dimensions);
        bool addSnake(Snake* snake);
        bool addPoint(Point p);
        bool rmPoint(Point p);
        void displayHandler(int displayMethod = -1);
        bool initBall();
        bool generateBall();
        short isFree(Point p);
        bool save(char name[MAXLINE]);
        bool load(char name[MAXLINE]);
};

#endif
