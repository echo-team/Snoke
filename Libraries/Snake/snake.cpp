#include "snake.h"

/**
 * @function Initializes snake
 * @param {Point} begin  - starting Point of a snake(where the tail segment will be situated)
 * @param {short} dir    - direction of snake's 'growth' as well as it's starting direction
 * @param {int}   length - the length of a 'new born' snake
 * @return {bool} - mark of whether the snake is successfully initialized
 */
bool Snake::init(Point begin, short dir, int length)
{
    if (dir == MVLEFT or dir == MVRIGHT or dir == MVUP or dir == MVDOWN)
    {
        /**
         * Pointer to the variable we want to change, depending on the dir variable
         * @type {short*}
         */
        short* changable;
        if (dir == MVLEFT or dir == MVRIGHT)
        {
            changable = &begin.x;
        }
        else
        {
            changable = &begin.y;
        }

        /**
         * The amount we will change the changable variable, depending on the dir variable
         * @type {short}
         */
        short value;
        if (dir == MVRIGHT or dir == MVDOWN)
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
        return true;
    }
    return false;
}

/**
 * @function The snake movement on the game field(should be called in each iteration of the game cycle, unless the snake is 'dead')
 * @param {bool**} labyrinth -  2-dimensional array defying current state of every point of the game field (blocked or not)
 * @param {Ball*}  ball      - a pointer to a Ball object(to check intersection with)
 * @param {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 change[0] - an array containing Points to add to the labyrinth
 *                 change[1] - an array containing Points to remove from the labyrinth
 * @return {bool} mark of whether the was a non-boundary non-ball collision
 */
bool Snake::move(bool** labyrinth, Ball* ball, Point* change[2])
{
    Point p;
    p.x = snakeBody.front().x;
    p.y = snakeBody.front().y;
    switch (direction)
    {
        case MVRIGHT:
            p.x++;
            break;
        case MVLEFT:
            p.x--;
            break;
        case MVDOWN:
            p.y++;
            break;
        case MVUP:
            p.y--;
            break;
    }
    moveHead(p, change);
    Point g;
    g.x = -1;
    g.y = -1;
    change[1][0] = g;
    switch (checkIntersection(labyrinth, ball, change))
    {
        case WALLUP:
            snakeBody.pop_front();
            p.y = gameFieldSize.y - 1;
            moveHead(p, change);
            break;
        case WALLBOT:
            snakeBody.pop_front();
            p.y = 1;
            moveHead(p, change);
            break;
        case WALLLEFT:
            snakeBody.pop_front();
            p.x = gameFieldSize.x - 1;
            moveHead(p, change);
            break;
        case WALLRIGHT:
            snakeBody.pop_front();
            p.x = 1;
            moveHead(p, change);
            break;
        case COLL:
            return true;
            break;
        case NOCOLL:
            break;
        case BALL:
            ball->generateBall(labyrinth);
            break;
    }
    return false;
    
}

/**
 * @function Moving snake head to a described by parameters position and updating the addition to the labyrinth
 * @param {Point}  p         - the desired position of movement
 * @param {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 change[0] - an array containing Points to add to the labyrinth
 *                 change[1] - an array containing Points to remove from the labyrinth
 */
void Snake::moveHead(Point p, Point* change[2])
{
    change[0][0] = p;
    snakeBody.push_front(p);
}

/**
 * @function Checking the given point for intersections with Ball, game boundaries, labyrinth
 * @param {bool**} labyrinth -  2-dimensional array defying current state of every point of the game field (blocked or not)
 * @param {Ball*}  ball      - a pointer to a Ball object(to check intersection with)
 * @param {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 change[0] - an array containing Points to add to the labyrinth
 *                 change[1] - an array containing Points to remove from the labyrinth
 * @return {short} a type of an intersection
 */
short Snake::checkIntersection(bool** labyrinth, Ball* ball, Point* change[2])
{
    Point hCoords = getHeadCoords();
    Point bCoords = ball->getCoords();
    Point q = snakeBody.back();
    if (checkWall(q, labyrinth) != COLL)
    {
        q.x = -1;
        q.y = -1;
    }
    change[1][0] = q;
    
    if (labyrinth[hCoords.x][hCoords.y] == true)
    {
        snakeBody.pop_back();
        return checkWall(hCoords, labyrinth);
    }
    else
    {
        if (hCoords.x != bCoords.x or hCoords.y != bCoords.y)
        {
            snakeBody.pop_back();
            return NOCOLL;
        }
        else
        {
            return BALL;
        }
    }
    return NOCOLL;
}

/**
 * @function Check given by parameters point on Wall collision
 * @param {Point}  coords    - coordinates(x, y) of the segment
 * @param {bool**} labyrinth -  2-dimensional array defying current state of every point of the game field (blocked or not)
 * @return {short} a type of an intersection
 */
short Snake::checkWall(Point coords, bool** labyrinth)
{
    if (coords.x == gameFieldSize.x - 1)
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
 * @function The method to set the direction where the snake is heading
 * @param {int} dir - direction
 */
void Snake::setDirection(int dir)
{
    if (dir != 0){
        if (direction + dir == 0)
        {
            return;
        }
        direction = dir;
    }
}

/**
 * @function The method to get the current direction without giving the direct access
 * @return {short}
 */
short Snake::getDirection()
{
    return direction;
}

/**
 * @function The method to get the coordinates(x, y) of the snake's head without giving the direct access
 * @return {Point}
 */
Point Snake::getHeadCoords()
{
    Point p;
    p.x = snakeBody.front().x;
    p.y = snakeBody.front().y;
    return p;
}

/**
 * @function The method to get the snake whole body coordinates(x ,y) without giving the direct access
 * @param {list<Point>} currBody - an array where the current snake body is copied
 */
void Snake::getCoords(std::list<Point>* currBody)
{
    currBody->assign(snakeBody.begin(), snakeBody.end());
}