#ifndef LABYRINTH_DISPLAYHANDLER_H
#define LABYRINTH_DISPLAYHANDLER_H

/**
 * Prerequisites:
 *     tested Snake.init
 *     tested Snake.move
 *     tested Labyrinth.setLabyrinth
 *     tested Labyrinth.addSnake
 */

#include "shared.h"
#include "Labyrinth/labyrinth.h"

/**
 * @brief method runs with noraml parameters
 */
TEST(Labyrinth_displayHandler, test1)
{
    initscr();
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
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
    endwin();
    SUCCEED();
}

TEST(Labyrinth_displayHandler, test2)
{
    initscr();
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    labyrinth.displayHandler(DISPPART);
    endwin();
    SUCCEED();
}

/**
 * @brief multiple executions with snkae moving
 */
TEST(Labyrinth_displayHandler, test3)
{
    initscr();
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
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

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    labyrinth.displayHandler();
    endwin();
    SUCCEED();
}

TEST(Labyrinth_displayHandler, test4)
{
    initscr();
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    labyrinth.displayHandler(DISPFULL);
    endwin();
    SUCCEED();
}

TEST(Labyrinth_displayHandler, test5)
{
    initscr();
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    labyrinth.displayHandler(DISPUPD);
    endwin();
    SUCCEED();
}

#endif // LABYRINTH_DISPLAYHANDLER_H
