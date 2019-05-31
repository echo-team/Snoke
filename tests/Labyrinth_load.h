#ifndef LABYRINTH_LOAD_H
#define LABYRINTH_LOAD_H

/**
 * Prerequisites:
 *     tested Snake.init
 *     tested Labyrinth.setLabyrinth
 *     tested Labyrinth.addSnake
 *     tested Labyrinth.displayHandler
 */

#include "shared.h"
#include "Labyrinth/labyrinth.h"

TEST(Labyrinth_load, test1)
{
    initscr();
    gameFieldSize.x = 70;
    gameFieldSize.y = 35;

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVDOWN;
    int lenght = 5;
    bool retVal = snake.init(begin, direction, lenght);
    if(!retVal)
    {
        FAIL();
    }

    Labyrinth labyrinth;
    retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
       FAIL();
    }

    labyrinth.displayHandler();

    char fileName[MAXLINE] = "testsave";
    retVal = labyrinth.load(fileName);
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
    endwin();
}

#endif // LABYRINTH_LOAD_H
