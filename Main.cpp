#include <curses.h>
#include "Libraries/Screens/mainMenu.h"
#include "Libraries/Game/game.h"

int main()
{
    initscr();
    start_color();

    /*MainMenu main;
    main.draw();
    */
    
    Game g;
    g.init(48, 100);
    g.run();
    
    refresh();
    endwin();
    return 0;
}
