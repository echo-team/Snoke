#include "screen.h"

/**
 * Drawing screen method
 * @virtual
 */
void Screen::draw()
{}

/**
 * Returns first widget of the screen
 * @return {Widget*}
 */
Widget* Screen::first()
{
    return root;
}

/**
 * Finds next focusable widget in tree
 * @param  {Widget*} start - start point for searching
 * @return {Widget*}
 */
Widget* Screen::next(Widget* start)
{
    Widget* current = start;
    char diving = true;

    do
    {
        if (diving && current->firstChild())
        {
            current = current->firstChild();
        }
        else if (current->next())
        {
            current = current->next();
            diving = true;
        }
        else if (current->parent())
        {
            current = current->parent();
            diving = false;
        }

        if (diving && current->event(EVENT_FOCUS))
        {
            return current;
        }
        if (current->parent())
        {
            diving = true;
        }
    }
    while (current != start);

    return current;
}

/**
 * Finds previous focusable widget in tree
 * @param  {Widget*} start - start point for searching
 * @return {Widget*}
 */
Widget* Screen::previous(Widget* start)
{
    Widget* current = start;
    char bubbling = true;

    do
    {
        if (bubbling && current->previous())
        {
            current = current->previous();
            bubbling = false;
        }
        else if (bubbling && current->parent())
        {
            current = current->parent();
        }
        else
        {
            if (current->lastChild())
            {
                current = current->lastChild();
            }
            else
            {
                bubbling = true;
            }
        }

        if (bubbling && current->event(EVENT_FOCUS))
        {
            return current;
        }
        if (current->parent() == NULL)
        {
            bubbling = false;
        }
    }
    while (current != start);

    return current;
}

/**
 * @constructor
 */
Screen::Screen() : root(new Widget)
{}
