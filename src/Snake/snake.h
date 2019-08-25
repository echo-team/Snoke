/**
 * @file snake.h
 * @author Yegor Ignatov
 * @brief Definitions and prototypes for Snake class
 * @version 0.1
 * @date 2019-05-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "../Common/common.h"
#include "../Labyrinth/labyrinth.h"
#include "../Labyrinth/change.h"
#include "../Ball/ball.h"

/**
 * @brief   the tested segment is intersecting with the upper boundary of the game field
 */
const int WALLUP = -3;
/**
 * @brief   the tested segment is intersecting with the bottom boundary of the game field
 */
const int WALLBOT = +3;
/**
 * @brief   the tested segment is intersecting with the left boundary of the game field
 */
const int WALLLEFT = -4;
/**
 * @brief   the tested segment is intersecting with the right boundary of the game field
 */
const int WALLRIGHT = +4;
/**
 * @brief   the tested segment is intersecting with a non-boundary Point of the game field
 */
const int COLL = 5;
/**
 * @brief   the tested segment is NOT intersecting with any Point of the game labyrinth
 */
const int NOCOLL = 6;
/**
 * @brief   the tested segment is intersecting with the Ball
 */
const int BALL = 7;

/**
 * @brief   snake's head is moving right
 */
const int MVRIGHT = +1;
/**
 * @brief   snake's head is moving down
 */
const int MVDOWN = +2;
/**
 * @brief   snake's head is moving left
 */
const int MVLEFT = -1;
/**
 * @brief   snake's head is moving up
 */
const int MVUP = -2;

/**
 * @var Point gameFieldSize
 * size of a game field(x, y)
 */
extern Point gameFieldSize;

/**
 * @class Snake snake.h
 * @brief   Describes the Snake entity of the game
 * @prop    direction   - current direction where the snake is heading
 * @prop    style       - array, which describes how should the snake be colored
 * @prop    snakeBody   - deque type array, containing positions of snake's body segments
 */
class Snake
{
    private:
        short direction;
        std::list<PointStyle> style;
        std::deque<Point> snakeBody;
        short checkIntersection(Point check, Labyrinth* laryrinth);
        short checkWisely(Point coords, Point bcoords);
        void moveHead(Point p, Change* change);
        void moveBack(Point p, Change* change);
    public:
        bool init(Point begin, short direction, int length);
        void setScheme();
        void getCoords(std::list<Point>* currBody);
        Point getHeadCoords();
        bool setDirection(int dir);
        short getDirection();
        bool move(Labyrinth* labyrinth);
};
#endif //SNAKE_H
