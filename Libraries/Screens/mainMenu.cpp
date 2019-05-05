#include "MainMenu.h"

/**
 * Draws main menu
 */
void MainMenu::draw()
{
    Logo snoke(0, 0, {' ', COLOR_WHITE, COLOR_WHITE}, {' ', COLOR_BLACK, COLOR_RED}, 0);
    int menuHeight        = 12,
        snokeBottomBorder = 3;
    Point consoleSize = getConsoleSize(),
          snokeSize   = snoke.getSize(),
          menuStartPoint, snokeStartPoint;

    snokeStartPoint.x = (consoleSize.x - snokeSize.x) / 2;
    snokeStartPoint.y = (consoleSize.y - snokeSize.y - menuHeight - snokeBottomBorder) / 2;
    snoke.setPosition(snokeStartPoint.x, snokeStartPoint.y);
    snoke.draw();

    menuStartPoint.x  = snokeStartPoint.x;
    menuStartPoint.y  = snokeStartPoint.y + snokeSize.y + snokeBottomBorder;

    Menu* menu = new Menu(menuStartPoint.x, menuStartPoint.y, snokeSize.x, menuHeight);
    menu->add("Profile");
    menu->add("Play");
    menu->add("Search");
    menu->add("Settings");
    menu->add("About game");
    menu->add("DONATE");

    this->root->add(menu);
    menu->draw();
}
