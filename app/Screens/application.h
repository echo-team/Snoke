#ifndef APPLICATION_H
#define APPLICATION_H
#include <list>
#include <map>
#include <ncurses.h>
#include "screen.h"
#include "../Widgets/widget.h"

/**
 * Singleton class manages stack of screens and navigation
 * @prop {map<Screen*>}                 screens       - container with screens
 * @prop {std::list<Widget*>}           history       - list of opened screens
 * @prop {Screen*}                      currentScreen - current showed screen
 * @prop {std::list<Widget*>::iterator} currentWidget - current focused widget
 */
class Application
{
    private:
        void focusFirst();
        Application();
        Application(const Application&);
        Application& operator=(Application&);
        std::map<char*, Screen*> screens;
        std::list<Screen*> history;
        Screen* currentScreen;
        Widget* currentWidget;

    public:
        static Application& instance();
        void load(char* name);
        void back();
        void add(char* name, Screen* screen);
        void execute();
};

/**
 * Instance of the main app manager class
 * @type {Application}
 */
extern Application& app;

#endif
