#ifndef BALL_GENERATEBALL_TEST_H
#define BALL_GENERATEBALL_TEST_H

#include "shared.h"
#include "Game/game.h"
#include "Ball/ball.h"
#include "Labyrinth/labyrinth.h"

/**
 * @brief method runs with normal parameters
 */
TEST(ball_init_test, test1) {
    gameFieldSize.x = 20;
    gameFieldSize.y = 10;
    Ball ball;
    Point dim = gameFieldSize;
    bool retVal = ball.init(dim);
    if(!retVal)
    {
        FAIL();
    }
    Game game;
    game.init(20, 100);

    Labyrinth labyrinth;
    labyrinth.setLabyrinth(dim);


}

#endif // BALL_GENERATEBALL_TEST_H
