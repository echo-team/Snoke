#ifndef LABYRINTH_SAVE_H
#define LABYRINTH_SAVE_H

#include "shared.h"
#include "Labyrinth/labyrinth.h"

TEST(Labyrinth_save, test1)
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
    retVal = labyrinth.save(fileName);
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

#endif // LABYRINTH_SAVE_H
