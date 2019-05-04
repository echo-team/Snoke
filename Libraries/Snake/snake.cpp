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

/**
 * @brief   Initializes snake
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

        for (int i = 0; i < length; i++)
        {
            snakeBody.push_front(begin);
            *changable += value;
        }
        direction = dir;
        return false;
    }
    return true;
}

/**
 * @brief   The snake movement on the game field(should be called in each iteration of the game cycle, unless the snake is 'dead')
 * @param   labyrinth  - the current state of the labyrinth object for intersection checking
 * @param   ball       - a pointer to a Ball object(to check intersection with)
 * @param   change     - 2-dimensional array of changes needed to be applied to the labyrinth
 * @param   changeSize - max(len(change[0]), len(change[1])))
 * @return             - mark of whether there was a non-boundary non-ball collision
 */
bool Snake::move(Labyrinth* labyrinth, Ball* ball, Point* change[2], int changeSize)
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
    switch (checkIntersection(frCoords, labyrinth, ball))
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
            moveBack(bCoords, change);
            return true;
        case NOCOLL:
            break;
        case BALL:
            bCoords.x = -1;
            bCoords.y = -1;
            change[1][0] = ball->getCoords();
            ball->generateBall(labyrinth, change, changeSize);
            change[0][0] = ball->getCoords();
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
        switch (checkIntersection(frCoords, labyrinth, ball))
        {
            case COLL:
                moveBack(bCoords, change);
                return true;
            case NOCOLL:
                break;
            case BALL:
                bCoords.x = -1;
                bCoords.y = -1;
                change[1][0] = ball->getCoords();
                ball->generateBall(labyrinth, change, changeSize);
                change[0][0] = ball->getCoords();
                break;
            default:
                break;
        }
    }

    /*
     * If there was no obstacle collision then proceed and add Points to the
     * change array, staging them for addition/removal to/from labyrinth
     */
    moveHead(frCoords, change);
    moveBack(bCoords, change);
    return false;

}

/**
 * @brief   Moving snake head to a described by parameters position and updating the addition to the labyrinth
 * @param   p      - the new head position
 * @param   change - 2-dimensional array of changes needed to be applied to the labyrinth
 */
void Snake::moveHead(Point p, Point* change[2])
{
    change[0][1] = p;
    snakeBody.push_front(p);
}

/**
 * @brief   Checking if we need to remove the back of the snake from the labyrinth(we don't in case it has eaten the Ball)
 * @param   p      - the desired position of movement
 * @param   change - 2-dimensional array of changes needed to be applied to the labyrinth
 */
void Snake::moveBack(Point p, Point* change[2])
{
    change[1][1] = p;
    if(p.x != -1 && p.y != -1)
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
short Snake::checkIntersection(Point check, Labyrinth* labyrinth, Ball* ball)
{
    if (!labyrinth->isFree(check))
    {
        return checkWisely(check, ball->getCoords());
    }
    return NOCOLL;

}

/**
 * @brief   If the Point of the labyrinth we are checking is not free then decide the type of collision
 * @param   coords  - Point we are checking for type of a collision
 * @param   bcoords - Point, containing the coordinates of the Ball
 * @return          - type of the collision
 */
short Snake::checkWisely(Point coords, Point bcoords)
{
    if(coords.x == bcoords.x && coords.y == bcoords.y)
    {
        return BALL;
    }
    else if (coords.x == gameFieldSize.x - 1)
    {
        return WALLRIGHT;
    }
    else if (coords.x == 0)
    {
        return WALLLEFT;
    }
    else if (coords.y == gameFieldSize.y - 1)
    {
        return WALLBOT;
    }
    else if (coords.y == 0)
    {
        return WALLUP;
    }
    return COLL;
}

/**
 * @brief   The method to set the direction where the snake is heading
 * @param   direction - direction of the snake we are trying to set
 */
void Snake::setDirection(int direction)
{
    if (direction == MVRIGHT || direction == MVLEFT || direction == MVUP || direction == MVDOWN){
        /*
         * If directions are opposite, do nothing
         */
        if (this->direction + direction == 0)
        {
            return;
        }

        this->direction = direction;
    }
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
    Point headCoords;
    headCoords.x = snakeBody.front().x;
    headCoords.y = snakeBody.front().y;
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
