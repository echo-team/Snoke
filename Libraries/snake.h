#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "common.cpp"
class Snake
{
private:
	short direction;
	std::deque<Point> snakeBody;
	std::list<PointStyle> style; 
public:
	void setScheme();
	void getCoords(std::list<Point> currBody);
	Point getHeadCoords();
	void setDirection(int dir = 0);
	void move();
};
#endif