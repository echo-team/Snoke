#include "application.h"

/**
 * Runs the main event loop
 */
void Application::execute()
{
    bool esc = false;

    while (!esc)
    {
        int command = getch();
        std::list<Widget*>::iterator tmp = currentWidget;

        if (command != ERR)
        {
            switch(command)
            {
                case (KEY_UP):

                    currentWidget = currentScreen->previous(currentWidget);
                    while (currentWidget != tmp && !(*currentWidget)->event(EVENT_FOCUS))
                    {
                        currentWidget = currentScreen->previous(currentWidget);
                    }

                    (*tmp)->dispatch(EVENT_UNFOCUS);
                    (*currentWidget)->dispatch(EVENT_FOCUS);
                    break;

                case (KEY_DOWN):

                    currentWidget = currentScreen->next(currentWidget);
                    while (currentWidget != tmp && !(*currentWidget)->event(EVENT_FOCUS))
                    {
                        currentWidget = currentScreen->next(currentWidget);
                    }

                    (*tmp)->dispatch(EVENT_UNFOCUS);
                    (*currentWidget)->dispatch(EVENT_FOCUS);
                    break;

                case (13):

                    esc = true;
                    break;
            }
        }
    }
}

/**
 * Loads screen
 * @param {char*} name - screen name
 */
void Application::load(char* name)
{
    history.push_back(currentScreen);
    currentScreen = screens[name];
    currentWidget = currentScreen->first();
    currentScreen->draw();
}

/**
 * Loads previously opened screen
 * @param {char*} name - screen name
 */
void Application::back()
{
    history.pop_back();
    currentScreen = *(std::prev(history.end(), 1));
    currentWidget = currentScreen->first();
    currentScreen->draw();
}

/**
 * Adds screen to the list of known screens
 * @param {char*}   name   - name to identify screen
 * @param {Screen*} screen - pointer to screen
 */
void Application::add(char* name, Screen* screen)
{
    screens.insert(std::pair<char*, Screen*>(name, screen));
}

/**
 * Singleton constructor
 * @constructor
 * @return {Application&}
 */
Application& Application::instance()
{
    static Application app;
    return app;
}

/**
 * Plug for defending from redefining
 * @constructor
 */
Application::Application()
{}

Application& app = Application::instance();
