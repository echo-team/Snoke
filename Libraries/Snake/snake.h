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
public:
	bool init(Point begin, short direction, int length);
	std::deque<Point> snakeBody;
	void setScheme();
	void getCoords(std::list<Point> currBody);
	Point getHeadCoords();
	void setDirection(int dir = 0);
	int getDirection();
	void move(bool** labyrinth, Ball* ball);
};
#endif
