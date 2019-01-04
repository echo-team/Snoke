#include "game.h"
#include <iostream>

int Game::init(int size, int sp){
	setLabyrinth(size);
    setSpeed(sp);
}

int Game::run(){
	initscr();                   // Переход в curses-режим
    printw("Hello world!\n");  // Отображение приветствия в буфер
    refresh();                   // Вывод приветствия на настоящий экран
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
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