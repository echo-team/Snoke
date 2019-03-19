#include "ball.h"

/**
 * Initialization
 * @param {Point} fieldSize - the size of the game field(x, y)
 */
bool Ball::init(Point fieldSize)
{
    seed_val = time(NULL);
    rng.seed(seed_val);
    distributionX = *(new std::uniform_int_distribution<int>(0, fieldSize.x - 1));
    distributionY = *(new std::uniform_int_distribution<int>(0, fieldSize.y - 1));
    position.style.letter = '0';
    return true;
}

/**
 * Generate the Ball
 * @param  {bool**} labyrinth - 2-dimensional array defying current state of every point of the game field (blocked or not)
 * @return {bool}             - mark of whether the ball was successfully generated
 */
bool Ball::generateBall(Labyrinth labyrinth, Point* change[2], int changeSize)
{
    Point p;
    /**
     * Generate numbers until u get a free spot
     */
    while (1)
    {
        p.x = distributionX(rng);
        p.y = distributionY(rng);
        if ((labyrinth.isFree(p) or inRemChange(p, change, changeSize)) and !inAddChange(p, change, changeSize))
        {
            break;
        }
    }
    position.x = p.x;
    position.y = p.y;
    return true; 
}

/**
 * Get the ball coords without giving the direct access
 * @return {Point} 
 */
Point Ball::getCoords()
{
    return position;
}

