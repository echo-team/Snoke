#include <ncurses.h>
#include "Libraries/Screens/application.h"
#include "Libraries/Screens/mainMenu.h"

int main()
{
    initscr();
    start_color();
    set_escdelay(0);
    curs_set(0);
    noecho();
    keypad(stdscr, true);

    app.add("MainMenu", new MainMenu());
    app.load("MainMenu");
    app.execute();

    refresh();
    endwin();
    return 0;
}
