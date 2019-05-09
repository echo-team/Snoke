#ifndef MAIN_H
#define MAIN_H
#include <ncurses.h>
#include "../Common/common.h"
#include "../Widgets/logo.h"
#include "../Widgets/menu.h"
#include "screen.h"

/**
 * Main menu class
 */
class MainMenu : public Screen
{
    public:
        void draw();
};

#endif
