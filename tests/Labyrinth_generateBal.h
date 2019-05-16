#ifndef LABYRINTH_GENERATEBALL_TEST_H
#define LABYRINTH_GENERATEBALL_TEST_H

#include "shared.h"
#include "Labyrinth/labyrinth.h"

/**
 * @brief method runs with normal parameters
 */
TEST(labyrinth_generateBall_test, test1) {
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;
    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.initBall();
    if(retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }

}

#endif // LABYRINTH_GENERATEBALL_TEST_H
