#ifndef SNAKE_INIT_H
#define SNAKE_INIT_H

#include "shared.h"
#include "Snake/snake.h"

/**
 * @brief Snake class object can be created
 */
TEST(Snake_init, test0){
    Snake snake;
    SUCCEED();
}

/**
 * @brief method runs with normal parameters
 */
TEST(Snake_init, test1) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

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
 * @brief negative test for crossing the upper border of valid region
 */
TEST(Snake_init, test2) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVUP;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

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
 * @brief negative test for crossing the left border of valid region
 */
TEST(Snake_init, test3) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVLEFT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

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
 * @brief negative test for 1-st of the staring Point being outside the valid area
 */
TEST(Snake_init, test4) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = -1;
    begin.y = 1;
    short direction = MVLEFT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

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
 * @brief negative test for the 2-nd coordinate of the staring Point being outside the valid area
 */
TEST(Snake_init, test5) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = -1;
    short direction = MVLEFT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

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
 * @brief negative test for both coordinates of the staring Point being outside the valid area
 */
TEST(Snake_init, test6) {

    /*
     * Minimal environment block for the Snake_init
     */
    Snake snake;
    Point begin;
    begin.x = -1;
    begin.y = -1;
    short direction = MVLEFT;
    int length = 5;

    bool retVal = snake.init(begin, direction, length);

    if(!retVal)
    {
        SUCCEED();
    }
    else
    {
        FAIL();
    }
}


#endif // SNAKE_INIT_H
