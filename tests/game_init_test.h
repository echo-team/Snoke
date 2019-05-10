#ifndef GAME_INIT_TEST_H
#define GAME_INIT_TEST_H

#include "shared.h"
#include "Game/game.h"

/**
 * Prerequisites:
 *     tested Labyrinth.setLabyrinth
 */

/**
 * @brief Game class object can be created
 */
TEST(game_init_test, test0){
    Game game;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(game_init_test, test1) {
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
TEST(game_init_test, test2) {
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
 * @brief negative test with incorrect speed value
 */
TEST(game_init_test, test3) {
    Game game;
    int size = 100;
    int speed = -10;
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
 * @brief negative test with both values being incorrect
 */
TEST(game_init_test, test4) {
    Game game;
    int size = 5;
    int speed = -5;
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

#endif // GAME_INIT_TEST_H
