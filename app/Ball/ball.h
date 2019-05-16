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
#include <random>
#include <ctime>

/**
 * @var Point gameFieldSize
 * size of a game field(x, y)
 */
extern Point gameFieldSize;


/**
 * @class Ball ball.h
 * @brief   Describes the Ball entity of the game
 * @prop    position           - Coordinates(x, y) of a Ball in the Console window
 * @prop    randomEngine       - variable, responible for the 'random' during the game
 * @prop    seed_val           - value 'feeded' to the 'random' generator
 * @prop    distributionX      - an equally likely int distribution for x coordinate of a Ball
 * @prop    distributionY      - an equally likely int distribution for y coordinate of a Ball
 */
class Ball
{
    private:
        Point position;
        std::mt19937 randomEngine;
        uint32_t seed_val;
    public:
        std::uniform_int_distribution<int> distributionX;
        std::uniform_int_distribution<int> distributionY;
        bool init(Point dim);
        Point getCoords();
        bool setCoords(Point p);
        std::mt19937* getRandomEngine();
};
#endif
