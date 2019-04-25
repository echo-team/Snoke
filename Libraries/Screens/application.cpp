#include "application.h"

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
