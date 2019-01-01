#include <list>

class Snake
{
private:
	short direction;
	list<Point> snakeBody;
	PointStyle style[]; 
public:
	setScheme();
	GetCoords();
	GetHeadCoords();
	move(short direction);
};

#include "snake.cpp"