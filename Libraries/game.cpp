#include "game.h"
#include <iostream>

int Game::init(){
	setLabyrinth(20);
    setSpeed();
    initscr();                   // Переход в curses-режим
    printw("Hello world!\n");  // Отображение приветствия в буфер
    refresh();                   // Вывод приветствия на настоящий экран
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
}

int Game::run(){
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
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout<<labyrinth[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}

void Game::setSpeed(){

}