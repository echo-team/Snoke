#ifndef APPLICATION_H
#define APPLICATION_H
#include "../Interface/navigator.h"
#include "screen.h"

/**
 * Singleton class manages stack of screens and navigation
 * @prop {map<Screen*>} screens        - container with screens
 * @prop {Screen*}      currentScreen  - current showed screen
 * @prop {Widget*}      currentWidget  - current focused widget
 */
class Application
{
    private:
        Application();
        Application(const Application&);
        Application& operator=(Application&);
        std::map<Screen*> screens;
        Screen* currentScreen;
        Widget* currentWidget;
    public:
        static Application& instance();
        void execute();
};

/**
 * Instance of the main app manager class
 * @type {Application}
 */
extern Application& app;

#endif
