#include "ball.h"

/**
 * @brief   Initialization
 * @param   fieldSize - the size of the game field(x, y)
 * @return            - mark of successful initialization
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
 * @brief   Generate the Ball
 * @param   labyrinth  - the current state of the labyrinth object for intersection checking
 * @param   change     - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   changeSize - max(len(change[0]), len(change[1])))
 * @return             - mark of whether the ball was successfully generated
 */
bool Ball::generateBall(Labyrinth labyrinth, Point* change[2], int changeSize)
{
    Point p;
    /*
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
 * @brief   Get the ball coords without giving the direct access
 */
Point Ball::getCoords()
{
    return position;
}
