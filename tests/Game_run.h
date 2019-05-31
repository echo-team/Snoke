#ifndef GAME_RUN_H
#define GAME_RUN_H

#include "shared.h"
#include "Game/game.h"

TEST(Game_run, test1)
{
    /*
     * Block initializing ncurses console in the current console window,
     * and setting some parameters
     */
    initscr();
    start_color();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    keypad(stdscr, true);

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

#endif // GAME_RUN_H
