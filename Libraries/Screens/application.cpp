#include "application.h"

/**
 * Runs the main event loop
 */
void execute()
{
    bool esc = false;
    short unit = 0;

    while (!esc)
    {
        int command = getch();

        if (command != ERR)
        {
            switch(command)
            {
                case (KEY_UP):

                    if (unit > 0)
                    {
                        unit--;
                        break;
                    }

                    currentWidget = currentScreen->previous();
                    break;

                case (KEY_DOWN):

                    if (unit < currentWidget->units() - 1)
                    {
                        unit++;
                        break;
                    }

                    currentWidget = currentScreen->next();
                    break;

                case (KEY_ESC):

                    return;
            }
        }
    }
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
