#include "snake.h"

bool Snake::init(Point begin, short dir, int length){
	if (abs(dir) == 1 or abs(dir) == 2){
		short* changable;
		if (abs(dir) == 1)
			changable = &begin.x;
		else
			changable = &begin.y;
		short value;
		if (dir > 0)
			value = 1;
		else
			value = -1;
		for (int i = 0; i < length; i++){
			snakeBody.push_front(begin);
			*changable += value;
		}
		direction = dir;
		valid = true;
		return true;
	}
	return false;
}


/**
* +1 -> moves right
* -1 -> moves left
* +2 -> moves down
* -2 -> moves up
*/
bool Snake::move(bool** labyrinth, Ball* ball, Point* change[2]){
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
	change[0][0] = p;
	Point g;
	g.x = -1;
	g.y = -1;
	change[1][0] = g;
	return checkIntersection(ball, labyrinth, change[1]);
	
}	

bool Snake::checkIntersection(Ball* ball, bool** labyrinth, Point change[1]){
	Point hCoords = getHeadCoords();
	Point bCoords = ball->getCoords();
	if (labyrinth[hCoords.x][hCoords.y] == true)
		return true;
	else{
		if (hCoords.x != bCoords.x or hCoords.y != bCoords.y){
			change[0] = snakeBody.back();
			snakeBody.pop_back();
		}
		else{
			ball->generateBall(labyrinth);
		}
	}
	return false;
}			

void Snake::setDirection(int dir){
	if (dir != 0){
		if (direction + dir == 0)
			return;
		direction = dir;
	}
}

int Snake::getDirection(){
	return direction;
}

Point Snake::getHeadCoords(){
	Point p;
	p.x = snakeBody.front().x;
	p.y = snakeBody.front().y;
	return p;
}

void Snake::getCoords(std::list<Point> currBody){
	copy(currBody.begin(), currBody.end(), snakeBody.begin());
}