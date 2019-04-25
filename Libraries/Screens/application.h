#ifndef APPLICATION_H
#define APPLICATION_H

/**
 * Singleton class manages stack of screens and navigation
 */
class Application
{
    private:
        Application();
        Application(const Application&);
        Application& operator=(Application&);
    public:
        static Application& instance();
};

/**
 * Instance of the main app manager class
 * @type {Application}
 */
extern Application& app;

#endif
