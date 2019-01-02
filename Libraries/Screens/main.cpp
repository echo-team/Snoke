/**
 * Draws main menu
 */
void MainScreen::draw()
{

    Point consoleSize = getConsoleSize(), snokeStartPoint, menuStartPoint;
    const char* snoke[5] =
         {
             "****  *   * *   *  *** ",
             "    * ** ** *  ** *   *",
             "  **  * * * * * * *   *",
             "    * *   * **  *  ****",
             "****  *   * *   * *   *"
         };

    snokeStartPoint.x = (consoleSize.x - 23) / 2;
    snokeStartPoint.y = (consoleSize.y - 19) / 2;
    menuStartPoint.x  = (consoleSize.x - 13) / 2;
    menuStartPoint.y  = snokeStartPoint.y + 6;

    for (int lineCounter = 0; lineCounter < 5; lineCounter++)
    {
        move(snokeStartPoint.y + lineCounter, snokeStartPoint.x);
        printw(snoke[lineCounter]);
    }

    Menu menu(menuStartPoint.x, menuStartPoint.y, 13, 14);
    menu.addButton("Profile");
    menu.addButton("Play");
    menu.addButton("Search");
    menu.addButton("Settings");
    menu.addButton("About game");
    menu.addButton("DONATE");
    menu.draw();

    Navigator navigator;
    navigator.pushUnit(&menu, 6);
    navigator.listen();
}
