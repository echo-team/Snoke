#include <ncurses.h>
#include "Libraries/Screens/mainMenu.h"

int main()
{
    initscr();
    start_color();

    MainMenu main;
    main.draw();

    refresh();
    endwin();
    return 0;
}
