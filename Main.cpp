#include <ncurses.h>
#include "Lbraries/Interface/interface.h"

int main()
{
    initscr();

    Menu menu(5, 5, 10, 10);
    menu.addButton("Start");
    menu.addButton("Continue");
    menu.addButton("Stop");
    menu.addButton("Quit");
    menu.draw();

    Navigator navigator;
    navigator.pushUnit(&menu, 4);
    navigator.listen();
    refresh();
    endwin();
    return 0;
}
