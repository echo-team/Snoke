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
    /**
     * @var {Widget*} current - start point for searching focusable widget
     * @var {bool}    diving  - flag for immersion into children of widget (false if there are no children and need go up)
     */
    Widget* current = start;
    bool diving = true;

    do
    {
        /**
         * There are 2 modes - immersion (checking picked widgets) and bubbling throuch widgets were already checked (diving == false)
         * If there are children - check them.
         * If there are no children, but next sibling exists - check it
         * Else - bubble to the last widget with sibling
         */
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

        /**
         * If listeners for focus event are binded - stop search
         * If the top widget reached - start diving again
         */
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
    /**
     * @var {Widget*} current - start point for searching focusable widget
     * @var {bool}    bubling - flag for bubbling to the parent of widget (false if previous siblings of widget exist)
     */
    Widget* current = start;
    char bubbling = true;

    do
    {
        /**
         * There are 2 modes - bubbling (checking picked widgets) and diving to the end of widget treen brunch (diving == false)
         * If it is possible and bubbling mode on - go to the previous sibling (with no child) or to the parent (if all children were checked)
         * Else - dive to the childfree subchild of the previous widget
         */
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

        /**
         * If it is bubbling now and it is possible to dispatch focus event - stop search
         * If the top widget reached - enable diving mode
         */
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
