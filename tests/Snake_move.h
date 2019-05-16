#ifndef SNAKE_MOVE_H
#define SNAKE_MOVE_H

#include "shared.h"
#include "Snake/snake.h"
#include "Labyrinth/labyrinth.h"
#include <iostream>

/**
 * @brief method runs with normal parameters and no collisions
 */
TEST(Snake_move, test1)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
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
 * @brief snake moves through the upper wall
 */
TEST(Snake_move, testwall1)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 5;
    short direction = MVUP;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    Point hCoords = snake.getHeadCoords();
    Point expCoords;
    expCoords.x = 1;
    expCoords.y = 18;
    ASSERT_EQ(hCoords.x, expCoords.x);
    ASSERT_EQ(hCoords.y, expCoords.y);
}

/**
 * @brief snake moves through the right wall
 */
TEST(Snake_move, testwall2)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 34;
    begin.y = 5;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    Point hCoords = snake.getHeadCoords();
    Point expCoords;
    expCoords.x = 1;
    expCoords.y = 5;
    ASSERT_EQ(hCoords.x, expCoords.x);
    ASSERT_EQ(hCoords.y, expCoords.y);
}

/**
 * @brief snake moves through the left wall
 */
TEST(Snake_move, testwall3)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 5;
    begin.y = 1;
    short direction = MVLEFT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    Point hCoords = snake.getHeadCoords();
    Point expCoords;
    expCoords.x = 38;
    expCoords.y = 1;
    ASSERT_EQ(hCoords.x, expCoords.x);
    ASSERT_EQ(hCoords.y, expCoords.y);
}

/**
 * @brief snake moves through the lower wall
 */
TEST(Snake_move, testwall4)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 5;
    begin.y = 14;
    short direction = MVDOWN;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    Point hCoords = snake.getHeadCoords();
    Point expCoords;
    expCoords.x = 5;
    expCoords.y = 1;
    ASSERT_EQ(hCoords.x, expCoords.x);
    ASSERT_EQ(hCoords.y, expCoords.y);
}

/**
 * @brief snake collides with itself by doing 3 consiquent left turns
 */
TEST(Snake_move, testIntersection1)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 10;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    snake.setDirection(MVDOWN);
    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    snake.setDirection(MVLEFT);
    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    snake.setDirection(MVUP);
    retVal = snake.move(&labyrinth);
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
 * @brief snake eats the ball
 */
TEST(Snake_move, testIntersection2)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 20;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 5;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    labyrinth.initBall();
    labyrinth.remPoint(labyrinth.ball.getCoords());
    Point ballCoords;
    ballCoords.x = 6;
    ballCoords.y = 1;
    labyrinth.ball.setCoords(ballCoords);
    labyrinth.addPoint(labyrinth.ball.getCoords());

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }


    Point hCoords = snake.getHeadCoords();
    Point expHCoords;
    expHCoords.x = 6;
    expHCoords.y = 1;
    ASSERT_EQ(hCoords.x, expHCoords.x);
    ASSERT_EQ(hCoords.y, expHCoords.y);

    std::list<Point> cpBody;
    snake.getCoords(&cpBody);
    Point bCoords = cpBody.back();
    Point expBCoords;
    expBCoords.x = 1;
    expBCoords.y = 1;
    ASSERT_EQ(bCoords.x, expBCoords.x);
    ASSERT_EQ(bCoords.y, expBCoords.y);
}

/**
 * @brief snake goes through the wall and collides with itself
 */
TEST(Snake_move, testIntersection3)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 5;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 1;
    short direction = MVRIGHT;
    int length = 10;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    snake.setDirection(MVDOWN);
    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    retVal = snake.move(&labyrinth);
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
 * @brief snake goes through the wall and collides with Ball
 */
TEST(Snake_move, testIntersection4)
{
    gameFieldSize.x = 40;
    gameFieldSize.y = 5;
    Labyrinth labyrinth;

    bool retVal = labyrinth.setLabyrinth(gameFieldSize);
    if(!retVal)
    {
        FAIL();
    }

    Snake snake;
    Point begin;
    begin.x = 1;
    begin.y = 3;
    short direction = MVRIGHT;
    int length = 10;

    retVal = snake.init(begin, direction, length);
    if(!retVal)
    {
        FAIL();
    }

    retVal = labyrinth.addSnake(&snake);
    if(!retVal)
    {
        FAIL();
    }

    labyrinth.initBall();
    labyrinth.remPoint(labyrinth.ball.getCoords());
    Point ballCoords;
    ballCoords.x = 10;
    ballCoords.y = 1;
    labyrinth.ball.setCoords(ballCoords);
    labyrinth.addPoint(labyrinth.ball.getCoords());

    snake.setDirection(MVDOWN);
    retVal = snake.move(&labyrinth);
    if(retVal)
    {
        FAIL();
    }

    Point hCoords = snake.getHeadCoords();
    Point expHCoords;
    expHCoords.x = 10;
    expHCoords.y = 1;
    ASSERT_EQ(hCoords.x, expHCoords.x);
    ASSERT_EQ(hCoords.y, expHCoords.y);

    std::list<Point> cpBody;
    snake.getCoords(&cpBody);
    Point bCoords = cpBody.back();
    Point expBCoords;
    expBCoords.x = 1;
    expBCoords.y = 3;
    ASSERT_EQ(bCoords.x, expBCoords.x);
    ASSERT_EQ(bCoords.y, expBCoords.y);

}



#endif // SNAKE_MOVE_H
