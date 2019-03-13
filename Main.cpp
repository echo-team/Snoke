#include <ncurses.h>
#include "Libraries/Interface/console.h"
#include "Libraries/Interface/menu.h"
//#include "Libraries/Screens/mainMenu.h"

int main()
{
    initscr();
    refresh();
    //start_color();

    //MainMenu main;
    //main.draw();
    Menu menu;
    menu.position(2, 2);
    menu.geometry(10, 8);
    menu.addButton("first");
    menu.addButton("second");
    menu.addButton("third");
    menu.addButton("forth");
    console.add(&menu);

    getch();

    refresh();
    endwin();
    return 0;
}
