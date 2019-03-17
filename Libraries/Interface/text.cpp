#include "text.h"

/**
 * Sets inner text of widget
 * @param {char*} innerText - text to set
 */
void Text::add(char* innerText)
{
    this->innerText = innerText;
}

/**
 * Gets inner text of widget
 * @return {char*}
 */
char* Text::text()
{
    return innerText;
}

/**
 * Draws widget
 */
void Text::draw()
{
    wmove(frame, 0, 0);
    wprintw(frame, innerText);
}

/**
 * @constructor
 */
Text::Text() : Widget(), innerText("")
{}
