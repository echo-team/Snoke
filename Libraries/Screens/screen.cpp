#include "screen.h"

/**
 * Drawing screen method
 * @virtual
 */
void Screen::draw()
{}

/**
 * @constructor
 */
Screen::Screen() : root(new Widget)
{}
