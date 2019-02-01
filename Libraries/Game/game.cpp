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
    set_escdelay(0);

    Point screenSize;
    getmaxyx(stdscr, screenSize.y, screenSize.x);

    Point p, g;
    p.x = 1;
    p.y = 1;
    int dir = 1, len = 5;
    initSnake(p, dir, len);

    curs_set(0); //"Убиваем" курсор
    //Включаем режим удобной работы с функциональными клавишами, другими словами KEY_UP и KEY_DOWN без этого не работали бы
    keypad(stdscr, true); 
    bool flag = false;

    Ball ball(dim);
    ball.generateBall(labyrinth);

    Point* change[2];
    change[0] = new Point [1];
    change[1] = new Point [1];
    while ( !flag )
    {

        int ch = getch();

        switch (ch){
            case ERR:
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
        flag = snake.move(labyrinth, &ball, change);
        updateLabyrinth(change, 1);
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
        if (flag) break;
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

void Game::initSnake(Point start, int dir, int len){
    snake.init(start, dir, len);
    for(auto it = snake.snakeBody.begin(); it != snake.snakeBody.end(); it++){
        labyrinth[(*it).x][(*it).y] = 1;
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

void Game::updateLabyrinth(Point* update[2],int size){
    for(int i = 0; i < size; i++){
        Point p = update[0][i];
        if(p.x >= 0 and p.y >= 0)
            labyrinth[p.x][p.y] = 1;
        p = update[1][i];
        if(p.x >= 0 and p.y >= 0)
            labyrinth[p.x][p.y] = 0;
    }
}

void Game::setSpeed(int sp){
    speed = sp;
}