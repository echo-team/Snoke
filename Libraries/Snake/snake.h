#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "../Common/common.cpp"
#include "../Ball/ball.h"

/**
 * @const {int} WALLUP    - the tested segment is intersecting with the upper boundary of the game field
 * @const {int} WALLBOT   - the tested segment is intersecting with the bottom boundary of the game field
 * @const {int} WALLLEFT  - the tested segment is intersecting with the left boundary of the game field
 * @const {int} WALLRIGHT - the tested segment is intersecting with the right boundary of the game field
 * @const {int} COLL      - the tested segment is intersecting with a non-boundary Point of the game field
 * @const {int} NOCOLL    - the tested segment is NOT intersecting with any Point of the game labyrinth
 * @const {int} BALL      - the tested segment is intersecting with the BALL
 */
#define WALLUP -3
#define WALLBOT +3
#define WALLLEFT -4
#define WALLRIGHT +4
#define COLL 5
#define NOCOLL 6
#define BALL 7

/**
* @const {int} MVRIGHT - snake's head is moving right
* @const {int} MVDOWN  - snake's head is moving down
* @const {int} MVLEFT  - snake's head is moving left
* @const {int} MVUP    - snake's head is moving up
*/
#define MVRIGHT +1
#define MVDOWN +2
#define MVLEFT -1
#define MVUP -2

/**
 * gameFieldSize - size of a game field(x, y)
 * @type {Point} 
 * @global
 */
extern Point gameFieldSize;
/**
 * Describes the snake entity of the game
 * @prop {short}            direction - current direction where the snake is heading;
 * @prop {list<PointStyle>} style     - an array, describing how should the snake be colored
 * @prop {deque<Point>}     snakeBody - a deque type array, containing sposition of snake's body segments
 */
class Snake
{
    private:
        short direction;
        std::list<PointStyle> style;
        std::deque<Point> snakeBody;
        short checkIntersection(bool** laryrinth, Ball* ball, Point* change[2]);
        short checkWall(Point coords, bool** labyrinth);
        void moveHead(Point p, Point* change[2]);
    public:
        bool init(Point begin, short direction, int length);
        void setScheme();
        void getCoords(std::list<Point>* currBody);
        Point getHeadCoords();
        void setDirection(int dir = 0);
        short getDirection();
        short move(bool** labyrinth, Ball* ball, Point* change[2]);
};
#endif