#include "snake.h"
Point Snake::getHeadCoords(){
	Point p;
	p.x = snakeBody.front().x;
	p.y = snakeBody.front().y;
	return p;
}

/**
* +1 -> moves right
* -1 -> moves left
* +2 -> moves down
* -2 -> moves up
*/
void Snake::move(){
	Point p;
	p.x = snakeBody.front().x;
	p.y = snakeBody.front().y;
	switch (direction){
		case 1:{
			p.x++;
			break;
		}
		case -1:{
			p.x--;
			break;
		}
		case 2:{
			p.y++;
			break;
		}
		case -2:{
			p.y--;
			break;
		}
	}
	snakeBody.push_front(p);
	/* Check that snake didb't eat the ball*/
	if (1){
		snakeBody.pop_back();
	}
}				

void Snake::setDirection(int dir){
	if (dir != 0){
		direction = dir;
	}
}

void Snake::getCoords(std::list<Point> currBody){
	copy(currBody.begin(), currBody.end(),snakeBody.begin());
}