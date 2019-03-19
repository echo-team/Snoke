#include "snake.h"

/**
 * Initializes snake
 * @param  {Point} begin  - starting Point of a snake(where the tail segment will be situated)
 * @param  {short} dir    - direction of snake's 'growth' as well as it's starting direction
 * @param  {int}   length - the length of a 'new born' snake
 * @return {bool}         - mark of whether the snake is successfully initialized
 */
bool Snake::init(Point begin, short dir, int length)
{
    begin.style.letter = '*';
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
        return false;
    }
    return true;
}

/**
 * The snake movement on the game field(should be called in each iteration of the game cycle, unless the snake is 'dead')
 * @param  {bool**} labyrinth - 2-dimensional array defying current state of every point of the game field (blocked or not)
 * @param  {Ball*}  ball      - a pointer to a Ball object(to check intersection with)
 * @param  {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                  change[0] - an array containing Points to add to the labyrinth
 *                  change[1] - an array containing Points to remove from the labyrinth
 * @return {bool}             - mark of whether there was a non-boundary non-ball collision
 */
bool Snake::move(Labyrinth labyrinth, Ball* ball, Point* change[2], int changeSize)
{
    Point frCoords = snakeBody.front();
    Point bCoords = snakeBody.back();
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
    bool flag = 0;
    switch (checkIntersection(frCoords, labyrinth, ball))
    {
        case WALLUP:
            frCoords.y = gameFieldSize.y - 2;
            flag = 1;
            break;
        case WALLBOT:
            frCoords.y = 1;
            flag = 1;
            break;
        case WALLLEFT:
            frCoords.x = gameFieldSize.x - 2;
            flag = 1;
            break;
        case WALLRIGHT:
            frCoords.x = 1;
            flag = 1;
            break;
        case COLL:
            moveBack(bCoords, change);
            return 1;
        case NOCOLL:
            break;
        case BALL:
            bCoords.x = -1;
            bCoords.y = -1;
            change[1][0] = ball->getCoords();
            ball->generateBall(labyrinth, change, changeSize);
            change[0][0] = ball->getCoords();
            break;
    }
    if(flag)
    {
        switch (checkIntersection(frCoords, labyrinth, ball))
        {
            case COLL:
                moveBack(bCoords, change);
                return 1;
            case NOCOLL:
                break;
            case BALL:
                bCoords.x = -1;
                bCoords.y = -1;
                change[1][0] = ball->getCoords();
                ball->generateBall(labyrinth, change, changeSize);
                change[0][0] = ball->getCoords();
                break;
        }
    }
    moveHead(frCoords, change);
    moveBack(bCoords, change);
    return 0;

}

/**
 * Moving snake head to a described by parameters position and updating the addition to the labyrinth
 * @param {Point}  p         - the desired position of movement
 * @param {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                 change[0] - an array containing Points to add to the labyrinth
 *                 change[1] - an array containing Points to remove from the labyrinth
 */
void Snake::moveHead(Point p, Point* change[2])
{
    change[0][1] = p;
    snakeBody.push_front(p);
}

void Snake::moveBack(Point p, Point* change[2])
{
    change[1][1] = p;
    if(p.x != -1 and p.y != -1)
    {
        snakeBody.pop_back();
    }
}

/**
 * Checking the given point for intersections with Ball, game boundaries, labyrinth
 * @param  {bool**} labyrinth - 2-dimensional array defying current state of every point of the game field (blocked or not)
 * @param  {Ball*}  ball      - a pointer to a Ball object(to check intersection with)
 * @param  {Point*} change    - 2-dimensional array of changes needed to be applied to the labyrinth
 *                  change[0] - an array containing Points to add to the labyrinth
 *                  change[1] - an array containing Points to remove from the labyrinth
 * @return {short}            - a type of an intersection
 */
short Snake::checkIntersection(Point check, Labyrinth labyrinth, Ball* ball)
{
    if (!labyrinth.isFree(check))
    {
        return checkWisely(check, ball->getCoords());
    }
    return NOCOLL;

}

short Snake::checkWisely(Point coords, Point bcoords)
{
    if(coords.x == bcoords.x and coords.y == bcoords.y)
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
 * The method to set the direction where the snake is heading
 * @param {int} direction - direction of the snake we are trying to set
 */
void Snake::setDirection(int direction)
{
    if (direction == MVRIGHT or direction == MVLEFT or direction == MVUP or direction == MVDOWN){
        if (this->direction + direction == 0)
        {
            return;
        }
        this->direction = direction;
    }
}

/**
 * The method to get the current direction without giving the direct access
 * @return {short}
 */
short Snake::getDirection()
{
    return this->direction;
}

/**
 * The method to get the coordinates(x, y) of the snake's head without giving the direct access
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
 * The method to get the snake whole body coordinates(x ,y) without giving the direct access
 * @param {list<Point>} currBody - an array where the current snake body is copied
 */
void Snake::getCoords(std::list<Point>* currBody)
{
    currBody->assign(snakeBody.begin(), snakeBody.end());
}
