#include <ncurses.h>
#include "Libraries/Screens/application.h"
#include "Libraries/Screens/mainMenu.h"
#include "Libraries/Game/game.h"

int main()
{
    initscr();
    start_color();
    keypad(stdscr, true);

<<<<<<< HEAD
    /*MainMenu main;
    main.draw();
    */

    Game g;
    g.init(70, 150);
    g.run();
=======
    app.add("MainMenu", new MainMenu());
    app.load("MainMenu");
    app.execute();
>>>>>>> origin/screens

    refresh();
    endwin();
    return 0;
}
