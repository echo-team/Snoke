#include "snake.h"

#define WALLUP -2
#define WALLBOT 2
#define WALLLEFT -1
#define WALLRIGHT 1
#define NOWCOLL 3
#define NOCOLL 4
#define BALL 0

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
	moveHead(p, change);
	Point g;
	g.x = -1;
	g.y = -1;
	change[1][0] = g;
	switch (checkIntersection(ball, labyrinth, change)){
		case WALLUP:{
			snakeBody.pop_front();
			p.y = dim.y - 1;
			moveHead(p, change);
			break;
		}
		case WALLBOT:{
			snakeBody.pop_front();
			p.y = 1;
			moveHead(p, change);
			break;
		}
		case WALLLEFT:{
			snakeBody.pop_front();
			p.x = dim.x - 1;
			moveHead(p, change);
			break;
		}
		case WALLRIGHT:{
			snakeBody.pop_front();
			p.x = 1;
			moveHead(p, change);
			break;
		}
		case NOWCOLL:{
			return true;
			break;
		}
		case NOCOLL:{
			break;
		}
		case BALL:{
			ball->generateBall(labyrinth);
			break;
		}
	}
	return false;
	
}


void Snake::moveHead(Point p, Point* change[2]){
	change[0][0] = p;
	snakeBody.push_front(p);
}

short Snake::checkIntersection(Ball* ball, bool** labyrinth, Point* change[2]){
	Point hCoords = getHeadCoords();
	Point bCoords = ball->getCoords();
	Point q = snakeBody.back();
	if (checkWall(q, labyrinth) != NOWCOLL){
		q.x = -1;
		q.y = -1;
	}
	change[1][0] = q;
	
	if (labyrinth[hCoords.x][hCoords.y] == true){
		snakeBody.pop_back();
		return checkWall(hCoords, labyrinth);
	}
	else{
		if (hCoords.x != bCoords.x or hCoords.y != bCoords.y){
			snakeBody.pop_back();
			return NOCOLL;
		}
		else{
			return BALL;
		}
	}
	return NOCOLL;
}

short Snake::checkWall(Point coords, bool** labyrinth){
	if (coords.x == dim.x - 1) return WALLRIGHT;
	else if (coords.x == 0) return WALLLEFT;
	else if (coords.y == dim.y - 1) return WALLBOT;
	else if (coords.y == 0) return WALLUP;
	return NOWCOLL;
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