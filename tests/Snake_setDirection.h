#ifndef SNAKE_SETDIRECTION_H
#define SNAKE_SETDIRECTION_H

/**
 * Prerequisites:
 *     tested Snake.init
 */

#include "shared.h"
#include "Snake/snake.h"

/**
 * @brief method runs with normal parameters
 */
TEST(Snake_setDirection, test1) {

    /*
     * Minimal environment block for the snake_init_test
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

    /*
     * if snake cannot be initialized in normal conditions - FAIL
     */
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.setDirection(MVDOWN);

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
 * @brief negative test of switching direction to the opposite of prior
 */
TEST(Snake_setDirection, test2) {

    /*
     * Minimal environment block for the snake_init_test
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

    /*
     * if snake cannot be initialized in normal conditions - FAIL
     */
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.setDirection(MVLEFT);

    if(!retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }

}

#endif // SNAKE_SETDIRECTION_H
