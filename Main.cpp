#include <ncurses.h>
#include "Lbraries/Menu/menu.h"

int main()
{
    Menu menu(5, 5, 10, 10);
    menu.addButton("Start");
    menu.addButton("Continue");
    menu.addButton("Stop");
    menu.addButton("Quit");

    initscr();                   // Переход в curses-режим

    menu.draw();

    refresh();                   // Вывод приветствия на настоящий экран
    getch();
    endwin();                    // Выход из curses-режима. Обязательная команда.
    return 0;
}
