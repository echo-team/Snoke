#ifndef BALL_INIT_H
#define BALL_INIT_H

#include "shared.h"
#include "Ball/ball.h"

/**
 * @brief Ball class object can be created
 */
TEST(Ball_init, test0){
    Ball ball;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(Ball_init, test1) {
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
TEST(Ball_init, test2) {
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

#endif // BALL_INIT_H
