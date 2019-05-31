#ifndef GAME_INIT_H
#define GAME_INIT_H

#include "shared.h"
#include "Game/game.h"

/**
 * Prerequisites:
 *     tested Labyrinth.setLabyrinth
 */

/**
 * @brief Game class object can be created
 */
TEST(Game_init, test0){
    Game game;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(Game_init, test1) {
    Game game;
    int size = 100;
    int speed = 150;
    bool retVal = game.init(size, speed);
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

/**
 * @brief negative test with incorrect size value
 */
TEST(Game_init, test2) {
    Game game;
    int size = 5;
    int speed = 150;
    bool retVal = game.init(size, speed);
    if(!retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

/**
 * @brief negative test with speed below the limit
 */
TEST(Game_init, test3) {
    Game game;
    int size = 20;
    int speed = 80;
    bool retVal = game.init(size, speed);
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

/**
 * @brief negative test with speed above the limit
 */
TEST(Game_init, test4) {
    Game game;
    int size = 20;
    int speed = 11500;
    bool retVal = game.init(size, speed);
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}


#endif // GAME_INIT_H
