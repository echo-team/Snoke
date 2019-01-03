#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include "common.cpp"
class Snake
{
private:
	short direction;
	std::list<Point> snakeBody;
	//PointStyle style[]; 
public:
	//void setScheme();
	void getCoords(std::list<Point> currBody);
	Point getHeadCoords();
	void move();
};
#endif