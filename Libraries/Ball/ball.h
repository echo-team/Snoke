/**
 * @file ball.h
 * @author Yegor Ignatov
 * @brief definitions and prototypes for Ball class
 * @version 0.1
 * @date 2019-05-03
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BALL_H
#define BALL_H
#include "../Common/common.h"
#include "../Labyrinth/labyrinth.h"
#include <random>
#include <ctime>


/**
 * @class Ball ball.h
 * @brief   Describes the Ball entity of the game
 */
class Ball
{
    private:
        /**
         * @prop    Point   position
         * @brief   Coordinates(x, y) of a Ball in the Console window
         */
        Point position;
        /**
         * @prop    std::mt19937    rng
         * @brief    variable, responible for the 'random' during the game
         */
        std::mt19937 rng;
        /**
         * @prop    uint32_t    seed_val
         * @brief   value 'feeded' to the 'random' generator
         */
        uint32_t seed_val;
        /**
         * @prop    std::uniform_int_distribution<int>  distributionX
         * @brief   an equally likely int distribution for x coordinate of a Ball
         */
        std::uniform_int_distribution<int> distributionX;
        /**
         * @prop    std::uniform_int_distribution<int>  distributionY
         * @brief   an equally likely int distribution for y coordinate of a Ball
         */
        std::uniform_int_distribution<int> distributionY;

    public:
        bool init(Point dim);
        bool generateBall(Labyrinth labyrinth, Point* change[2], int changeSize);
        Point getCoords();
};
#endif
