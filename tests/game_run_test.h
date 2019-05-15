#ifndef GAME_RUN_TEST_H
#define GAME_RUN_TEST_H

#include "shared.h"
#include "Game/game.h"

TEST(game_run_test, test1)
{
    initscr();
    Game game;
    int size = 100;
    int speed = 150;
    int cycles = 5;
    bool retVal = game.init(size, speed, cycles);
    if(!retVal)
    {
        FAIL();
    }

    retVal = game.run();
    endwin();
    if(retVal)
    {
        FAIL();
    }
    else
    {
        SUCCEED();
    }
}

#endif // GAME_RUN_TEST_H
