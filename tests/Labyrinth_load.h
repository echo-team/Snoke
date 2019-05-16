#ifndef LABYRINTH_LAOD_TEST_H
#define LABYRINTH_LAOD_TEST_H

#include "shared.h"
#include "Labyrinth/labyrinth.h"

TEST(labyrinth_load_test, test1)
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

#endif // LABYRINTH_LAOD_TEST_H
