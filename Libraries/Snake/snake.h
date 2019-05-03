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
#include "../Ball/ball.h"
#include "../Labyrinth/labyrinth.h"

/**
 * @brief   the tested segment is intersecting with the upper boundary of the game field
 */
#define WALLUP -3
/**
 * @brief   the tested segment is intersecting with the bottom boundary of the game field
 */
#define WALLBOT +3
/**
 * @brief   the tested segment is intersecting with the left boundary of the game field
 */
#define WALLLEFT -4
/**
 * @brief   the tested segment is intersecting with the right boundary of the game field
 */
#define WALLRIGHT +4
/**
 * @brief   the tested segment is intersecting with a non-boundary Point of the game field
 */
#define COLL 5
/**
 * @brief   the tested segment is NOT intersecting with any Point of the game labyrinth
 */
#define NOCOLL 6
/**
 * @brief   the tested segment is intersecting with the Ball
 */
#define BALL 7

/**
 * @brief   snake's head is moving right
 */
#define MVRIGHT +1
/**
 * @brief   snake's head is moving down
 */
#define MVDOWN +2
/**
 * @brief   snake's head is moving left
 */
#define MVLEFT -1
/**
 * @brief   snake's head is moving up
 */
#define MVUP -2

/**
 * @var Point gameFieldSize
 * size of a game field(x, y)
 */
extern Point gameFieldSize;

/**
 * @class Snake snake.h
 * @brief   Describes the Snake entity of the game
 */
class Snake
{
    private:
        /**
         * @prop    short                   direction
         * @brief   current direction where the snake is heading;
         */
        short direction;
        /**
         * @prop    std::list<PointStyle>   style
         * @brief   array, which describes how should the snake be colored
         */
        std::list<PointStyle> style;
        /**
         * @prop    std::deque<Point>       snakeBody
         * @brief   deque type array, containing positions of snake's body segments
         */
        std::deque<Point> snakeBody;
        short checkIntersection(Point check, Labyrinth laryrinth, Ball* ball);
        short checkWisely(Point coords, Point bcoords);
        void moveHead(Point p, Point* change[2]);
        void moveBack(Point p, Point* cahnge[2]);
    public:
        bool init(Point begin, short direction, int length);
        void setScheme();
        void getCoords(std::list<Point>* currBody);
        Point getHeadCoords();
        void setDirection(int dir = 0);
        short getDirection();
        bool move(Labyrinth labyrinth, Ball* ball, Point* change[2], int changeSize);
};
#endif //SNAKE_H
