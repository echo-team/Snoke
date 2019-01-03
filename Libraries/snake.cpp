#include "snake.h"
Point Snake::getHeadCoords(){
	Point p;
	p.x = snakeBody.front().x;
	p.y = snakeBody.front().y;
	return p;
}

void Snake::move(){

}

void Snake::getCoords(std::list<Point> currBody){
	copy(currBody.begin(), currBody.end(),snakeBody.begin());
}