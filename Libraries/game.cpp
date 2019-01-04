#include "game.h"
#include <iostream>
#include <unistd.h>

int Game::init(int size, int sp){
	setLabyrinth(size);
    setSpeed(sp);
}

int Game::run(){

    initscr();

    nodelay(stdscr, TRUE);

    Point screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);

    Point p;
    p.x = screenSize.x / 2;
    p.y = screenSize.y / 2;
	Snake snake;
	for (int i = 0; i < 4; i++){
		snake.snakeBody.push_front(p);
		p.x--;
	}

    unsigned choice = 0; //Выбор пользователя

    curs_set(0); //"Убиваем" курсор
    //Включаем режим удобной работы с функциональными клавишами, другими словами KEY_UP и KEY_DOWN без этого не работали бы
    keypad(stdscr, true); 

    while ( true )
    {

    	int ch = getch();

    	switch (ch){
    		case ERR:
    			snake.setDirection(0);
    			break;
    		case KEY_UP:
    			snake.setDirection(-2);
    			break;
    		case KEY_DOWN:
    			snake.setDirection(2);
    			break;
    		case KEY_LEFT:
    			snake.setDirection(-1);
    			break;
    		case KEY_RIGHT:
    			snake.setDirection(1);
    			break;
    	}
    	snake.move();

    	clear();
    	for(auto it = snake.snakeBody.begin(); it != snake.snakeBody.end(); it++){
    		mvaddch((*it).y, (*it).x, '*');
    	}
    	flushinp();
    	usleep(speed);
    	refresh();
    }

    endwin();
    return 0;
}

void Game::setLabyrinth(int size){
	labyrinth = new bool* [size];
	for(int i = 0; i < size; i++){
		labyrinth[i] = new bool [size];
	}
	for(int i = 0; i < size; i++){
		labyrinth[0][i] = 1;
		labyrinth[i][0] = 1;
		labyrinth[i][size - 1] = 1;
		labyrinth[size - 1][i] = 1;
	}
}

void Game::setSpeed(int sp){
	speed = sp;
}