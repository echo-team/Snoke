#include "game.h"

bool Game::init(int size, int sp){
    dim.x = size;
    dim.y = size/2;
    setLabyrinth(dim);
    setSpeed(sp);
    return true;
}

int Game::run(){

    initscr();

    nodelay(stdscr, TRUE);

    Point screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);

    Point p, g;
    p.x = 1;
    p.y = 1;
    snake.init(p, 1, 10);

    curs_set(0); //"Убиваем" курсор
    //Включаем режим удобной работы с функциональными клавишами, другими словами KEY_UP и KEY_DOWN без этого не работали бы
    keypad(stdscr, true); 
    bool flag = false;

    Ball ball(dim);
    ball.generateBall(labyrinth);
    while ( !flag )
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
            case 'q':
                flag = true;
                break;

    	}
        if (flag) break;
    	if(snake.move(labyrinth, &ball)){
            break;
        }

    	clear();
        displayLabyrinth();
    	for(auto it = snake.snakeBody.begin(); it != snake.snakeBody.end(); it++){
    		mvaddch((*it).y, (*it).x, '*');
    	}
        g = ball.getCoords();
        mvaddch(g.y, g.x, '*');
    	flushinp();
    	mSleep(speed);
    	refresh();
    }

    endwin();
    return 0;
}

void Game::mSleep(int time){
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Game::setLabyrinth(Point dim){
	labyrinth = new bool* [dim.x];
	for(int i = 0; i < dim.x; i++){
		labyrinth[i] = new bool [dim.y];
	}
	for(int i = 0; i < dim.x; i++){
		labyrinth[i][0] = 1;
		labyrinth[i][dim.y - 1] = 1;
	}
    for(int i = 0; i < dim.y; i++){
        labyrinth[0][i] = 1;
        labyrinth[dim.x - 1][i] = 1;
    }
}

void Game::displayLabyrinth(){
    for(int i = 0; i < dim.x; i++){
        for(int j = 0; j < dim.y; j++){
            if(labyrinth[i][j]){
                mvaddch(j, i, '*');
            }
        }
    }
}

void Game::updateLabyrinth(Point update[],int size){

}

void Game::setSpeed(int sp){
	speed = sp;
}