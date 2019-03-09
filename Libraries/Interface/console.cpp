#include "console.h"

/**
 * @constructor
 * Private plug for constructor in order to hold singularity of instance
 */
Console::Console() : Widget()
{}

/**
 * @constructor
 * Private plug for operator new (copy) in order to hold singularity of instance
 * @param {const Console&} - existing instance of console
 */
Console::Console(const Console&)
{}

/**
 * @constructor
 * Private plug for operator assignment in order to hold singularity of instance
 * @param {Console&} - existing instance of console
 */
Console& Console::operator=(Console&)
{}

/**
 * Returns link to the static Console instance defineg in Singleton class
 * @return {Console&}
 */
Console& Console::instance()
{
    static Console console;
    return console;
}
