#ifndef SNAKE_H
#define SNAKE_H
#include <list>
#include <deque>
#include "../Common/common.cpp"
#include "../Ball/ball.h"

extern Point dim;

class Snake
{
private:
	short direction;
	std::list<PointStyle> style; 
	bool valid = false;
	short checkIntersection(Ball* ball, bool** laryrinth, Point* change[2]);
	short checkWall(Point coords, bool** labyrinth);
	void moveHead(Point p, Point* change[2]);
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
