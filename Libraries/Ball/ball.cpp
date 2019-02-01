#include "ball.h"

/**
 * @constructor
 * @param {Point} dim - dimensions of the game field
 */
bool Ball::init(Point dim)
{
    seed_val = time(NULL);
    rng.seed(seed_val);
    std::uniform_int_distribution<int> distribution1(0, dim.x - 1);
    distributionX = distribution1;
    std::uniform_int_distribution<int> distribution2(0, dim.y - 1);
    distributionY = distribution2;
    return true;
}

/**
 * @function Generate the Ball
 * @param {bool**} labyrinth -  2-dimensional array defying current state of every point of the game field (blocked or not)
 * @return {bool} mark of whether the ball was successfully generated
 */
bool Ball::generateBall(bool** labyrinth)
{
    Point p;
    /**
     * Generate numbers until u get a free spot
     */
    while (1){
        p.x = distributionX(rng);
        p.y = distributionY(rng);
        if (labyrinth[p.x][p.y] == false)
        {
            break;
        }
    }
    position.x = p.x;
    position.y = p.y;
    return true; 
}

/**
 * @function Get the ball coords without giving the direct access
 * @return {Point} 
 */
Point Ball::getCoords()
{
    return position;
}

