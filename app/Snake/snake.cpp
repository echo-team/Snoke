/**
 * @file snake.cpp
 * @author Yegor Ignatov
 * @brief realisation of Snake class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "snake.h"
#include "../Common/common.h"

/**
 * @brief   Initializes snake as an entity without ancoring it anywhere
 * @param   begin  - starting Point of a snake(where the tail segment will be situated)
 * @param   dir    - direction of snake's 'growth' as well as it's starting direction
 * @param   length - the length of a 'new born' snake
 * @return         - mark of whether the snake is successfully initialized
 */
bool Snake::init(Point begin, short dir, int length)
{
    begin.style.letter = '*';
    if (dir == MVLEFT || dir == MVRIGHT || dir == MVUP || dir == MVDOWN)
    {
        /*
         * Pointer to the variable we want to change, depending on the dir variable
         * @type {short*}
         */
        short* changable;
        if (dir == MVLEFT || dir == MVRIGHT)
        {
            changable = &begin.x;
        }
        else
        {
            changable = &begin.y;
        }

        /*
         * The amount we will change the changable variable, depending on the dir variable
         * @type {short}
         */
        short value;
        if (dir == MVRIGHT || dir == MVDOWN)
        {
            value = 1;
        }
        else
        {
            value = -1;
        }

        /*
         * Snake can not exist in non-positive coords
         */
        if (*changable + value * length < 1 || begin.x < 1 || begin.y < 1)
        {
            return false;
        }

        for (int i = 0; i < length; i++)
        {
            snakeBody.push_front(begin);
            *changable += value;
        }
        direction = dir;
        return true;
    }
    return false;
}

/**
 * @brief   The snake movement on the game field(should be called in each iteration of the game cycle, unless the snake is 'dead')
 * @param   labyrinth  - the current state of the labyrinth object for intersection checking
 * @param   ball       - a pointer to a Ball object(to check intersection with)
 * @param   change     - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   changeSize - max(len(change[0]), len(change[1])))
 * @return             - mark of whether there was a non-boundary non-ball collision
 */
bool Snake::move(Labyrinth* labyrinth)
{
    Point frCoords = snakeBody.front();
    Point bCoords = snakeBody.back();

    /*
     * Getting the future head coords to check intersections
     */
    switch (direction)
    {
        case MVRIGHT:
            frCoords.x++;
            break;
        case MVLEFT:
            frCoords.x--;
            break;
        case MVDOWN:
            frCoords.y++;
            break;
        case MVUP:
            frCoords.y--;
            break;
    }

    /*
     * Flag of whether there was a wall collision and therefor
     * we need to teleport snake's head to the opposite side of the labyrinth
     */
    bool wallFlag = 0;

    /*
     * Checking intersections with borders, obstacles and Ball and deciding where to put the head of the snake
     */
    switch (checkIntersection(frCoords, labyrinth))
    {
        case WALLUP:
            frCoords.y = gameFieldSize.y - 2;
            wallFlag = 1;
            break;
        case WALLBOT:
            frCoords.y = 1;
            wallFlag = 1;
            break;
        case WALLLEFT:
            frCoords.x = gameFieldSize.x - 2;
            wallFlag = 1;
            break;
        case WALLRIGHT:
            frCoords.x = 1;
            wallFlag = 1;
            break;
        case COLL:
            moveBack(bCoords, &labyrinth->change);
            return true;
        case NOCOLL:
            break;
        case BALL:
            bCoords.x = -1;
            bCoords.y = -1;
            labyrinth->change.remPoint(labyrinth->ball.getCoords());
            labyrinth->generateBall();
            labyrinth->change.addPoint(labyrinth->ball.getCoords());
            break;
        default:
            break;
    }

    /*
     * If there was a wall collision, then we need to check
     * the new head position of the snake for colliding with Ball or obstacles
     */
    if(wallFlag)
    {
        switch (checkIntersection(frCoords, labyrinth))
        {
            case COLL:
                moveBack(bCoords, &labyrinth->change);
                return true;
            case NOCOLL:
                break;
            case BALL:
                bCoords.x = -1;
                bCoords.y = -1;
                labyrinth->change.remPoint(labyrinth->ball.getCoords());
                labyrinth->generateBall();
                labyrinth->change.addPoint(labyrinth->ball.getCoords());
                break;
            default:
                break;
        }
    }

    /*
     * If there was no obstacle collision then proceed and add Points to the
     * change array, staging them for addition/removal to/from labyrinth
     */
    moveHead(frCoords, &labyrinth->change);
    moveBack(bCoords, &labyrinth->change);
    return false;

}

/**
 * @brief   Moving snake head to a described by parameters position and updating the addition to the labyrinth
 * @param   p      - the new head position
 * @param   change - 2-dimensional array of changes needed to be applied to the labyrinth
 */
void Snake::moveHead(Point p, Change* change)
{
    change->addPoint(p);
    snakeBody.push_front(p);
}

/**
 * @brief   Checking if we need to remove the back of the snake from the labyrinth(we don't in case it has eaten the Ball)
 * @param   p      - the desired position of movement
 * @param   change - 2-dimensional array of changes needed to be applied to the labyrinth
 */
void Snake::moveBack(Point p, Change* change)
{
    if(change->remPoint(p))
    {
        snakeBody.pop_back();
    }
}

/**
 * @brief   Checking the given point for intersections with Ball, borders, obstacles
 * @param   check     - a Point to check
 * @param   labyrinth - 2-dimensional array defying current state of every point of the game field (blocked or not)
 * @param   ball      - a pointer to a Ball object(to check intersection with)
 * @return            - type of collision
 */
short Snake::checkIntersection(Point check, Labyrinth* labyrinth)
{
    if ((!labyrinth->isFree(check)) == 1)
    {
        return checkWisely(check, labyrinth->ball.getCoords());
    }
    return NOCOLL;

}

/**
 * @brief   If the Point of the labyrinth we are checking is not free then decide the type of collision
 * @param   check  - Point we are checking for type of a collision
 * @param   bCoords - Point, containing the coordinates of the Ball
 * @return          - type of the collision
 */
short Snake::checkWisely(Point check, Point bCoords)
{
    if(check.x == bCoords.x && check.y == bCoords.y)
    {
        return BALL;
    }
    else if (check.x == gameFieldSize.x - 1)
    {
        return WALLRIGHT;
    }
    else if (check.x == 0)
    {
        return WALLLEFT;
    }
    else if (check.y == gameFieldSize.y - 1)
    {
        return WALLBOT;
    }
    else if (check.y == 0)
    {
        return WALLUP;
    }
    return COLL;
}

/**
 * @brief   The method to set the direction where the snake is heading
 * @param   direction - direction of the snake we are trying to set
 * @return            - mark of successful set
 */
bool Snake::setDirection(int direction)
{
    if (direction == MVRIGHT || direction == MVLEFT || direction == MVUP || direction == MVDOWN){
        /*
         * If directions are opposite, do nothing
         */
        if (this->direction + direction == 0)
        {
            return false;
        }

        this->direction = direction;
    }
    return true;
}

/**
 * @brief   The method to get the current direction without giving the direct access
 */
short Snake::getDirection()
{
    return this->direction;
}

/**
 * @brief   The method to get the coordinates(x, y) of the snake's head without giving the direct access
 */
Point Snake::getHeadCoords()
{
    Point headCoords = snakeBody.front();
    return headCoords;
}

/**
 * @brief   The method to get the snake whole body coordinates(x ,y) without giving the direct access
 * @param   currBody - an array where the current snake body is copied
 */
void Snake::getCoords(std::list<Point>* currBody)
{
    currBody->assign(snakeBody.begin(), snakeBody.end());
}
