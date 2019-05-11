#ifndef BALL_INIT_TEST_H
#define BALL_INIT_TEST_H

#include "shared.h"
#include "Ball/ball.h"

/**
 * Prerequisites:
 *     tested Labyrinth.setLabyrinth
 */

/**
 * @brief Ball class object can be created
 */
TEST(ball_init_test, test0){
    Ball ball;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(ball_init_test, test1) {
    Ball ball;
    Point dim;
    dim.x = 20;
    dim.y = 10;
    bool retVal = ball.init(dim);
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
 * @brief negative test with incorrect parameters
 */
TEST(ball_init_test, test2) {
    Ball ball;
    Point dim;
    dim.x = 2;
    dim.y = 10;
    bool retVal = ball.init(dim);
    if(!retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}

#endif // BALL_INIT_TEST_H
