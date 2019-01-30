#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "../Common/common.cpp"
#include "../Ball/ball.h"

class Snake
{
private:
	short direction;
	std::list<PointStyle> style; 
	bool valid = false;
	bool checkIntersection(Ball* ball, bool** laryrinth, Point change[1]);
public:
	bool init(Point begin, short direction, int length);
	std::deque<Point> snakeBody;
	void setScheme();
	void getCoords(std::list<Point> currBody);
	Point getHeadCoords();
	void setDirection(int dir = 0);
	int getDirection();
	bool move(bool** labyrinth, Ball* ball, Point* change[2]);
};
#endif
