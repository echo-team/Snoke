#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "../Common/common.cpp"
class Snake
{
private:
	short direction = 0;
	std::list<PointStyle> style; 
public:
	std::deque<Point> snakeBody;
	void setScheme();
	void getCoords(std::list<Point> currBody);
	Point getHeadCoords();
	void setDirection(int dir = 0);
	int getDirection();
	void move();
};
#endif
