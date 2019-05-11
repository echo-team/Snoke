#ifndef LABYRINTH_ADDSNAKE_TEST_H
#define LABYRINTH_ADDSNAKE_TEST_H

#include "shared.h"
#include "Labyrinth/labyrinth.h"
#include <iostream>

/**
 * Prerequisites:
 *     tested Labyrinth.setLabyrinth
 *     tested Snake.init
 */

/**
 * @brief method runs with normal parameters
 */
TEST(labyrinth_addSnake_test, test1) {
    gameFieldSize.x = 70;
    gameFieldSize.y = 35;

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVDOWN;
    int lenght = 5;
    bool retVal = snake.init(begin, direction, lenght);
    if(!retVal)
    {
        FAIL();
    }

    Labyrinth labyrinth;
    Point size;
    size.x = 70;
    size.y = 35;
    retVal = labyrinth.setLabyrinth(size);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
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
 * @brief negative test with incorrect input snake(doesn't fit)
 */
TEST(labyrinth_addSnake_test, test2) {

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVDOWN;
    int lenght = 45;
    bool retVal = snake.init(begin, direction, lenght);
    if(!retVal)
    {
        FAIL();
    }

    Labyrinth labyrinth;
    Point size;
    size.x = 70;
    size.y = 35;
    retVal = labyrinth.setLabyrinth(size);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
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
 * @brief negative test with incorrect input snake(doesn't fit)
 */
TEST(labyrinth_addSnake_test, test3) {

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int lenght = 70;
    bool retVal = snake.init(begin, direction, lenght);
    if(!retVal)
    {
        FAIL();
    }

    Labyrinth labyrinth;
    Point size;
    size.x = 70;
    size.y = 35;
    retVal = labyrinth.setLabyrinth(size);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
       SUCCEED();
    }
    else
    {
        FAIL();
    }
}

#endif // LABYRINTH_ADDSNAKE_TEST_H
