/**
 * @file ball.cpp
 * @author Yegor Ignatov
 * @brief realisation of Ball class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "ball.h"

/**
 * @brief   Initialization
 * @param   fieldSize - the size of the game field(x, y)
 * @return            - mark of successful initialization
 */
bool Ball::init(Point fieldSize)
{
    if(fieldSize.x > 2 && fieldSize.y > 2)
    {
        seed_val = time(NULL);
        rng.seed(seed_val);
        distributionX = *(new std::uniform_int_distribution<int>(1, fieldSize.x - 1));
        distributionY = *(new std::uniform_int_distribution<int>(1, fieldSize.y - 1));
        position.style.letter = '0';
        return true;
    }
    return false;
}

/**
 * @brief   Get the ball coords without giving the direct access
 */
Point Ball::getCoords()
{
    return position;
}

/**
 * @brief   Sets coordinates of the ball to given if they are correct
 * @param   p - point to copy coords from
 * @return    - mark os succesful copy
 */
bool Ball::setCoords(Point p)
{
    if(p.x >= 1 && p.x <= gameFieldSize.x && p.y >= 1 && p.y <= gameFieldSize.y)
    {
        this->position.x = p.x;
        this->position.y = p.y;
        return true;
    }
    return false;
}

std::mt19937* Ball::getRng()
{
    return &this->rng;
}
