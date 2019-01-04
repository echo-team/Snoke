#include <ncurses.h>
#include <iostream>
#include "Libraries/common.cpp"
#include "Libraries/snake.h"
#include "Libraries/game.h"


int main()
{
	Game g;
	g.init(30, 100000);
	/*Snake me;
	Point p;
	p.x = 1;
	p.y = 2;
	for (int i = 0; i < 6; i++){
		me.snakeBody.push_front(p);
		p.x++;
		p.y += 3;
	}
	for(auto it = me.snakeBody.begin(); it != me.snakeBody.end(); it++){
		std::cout<<(*it)<<' ';
	}*/
	g.run();
	return 0;
}
