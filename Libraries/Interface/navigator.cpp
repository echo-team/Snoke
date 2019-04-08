#include "navigator.h"

/**
 * Gets widgets next sibling
 * @param  {Widget*} widget - widget to get sibling
 * @return {Widget*}        - if widget is last in parents widgets array, then NULL
 */
Widget* Navigator::nextSibling(Widget* widget)
{
    Widget* parent = current->parent();
    std::vector<Widget*> children = parent->children();
    short index = std::find(children.begin(), children.end(), widget) - children.begin() + 1;

    if (index < children.size())
    {
        return children[index];
    }
    else
    {
        return NULL;
    }
}

/**
 * Gets widgets previous sibling
 * @param  {Widget*} widget - widget to get sibling
 * @return {Widget*}        - if widget is last in parents widgets array, then NULL
 */
Widget* Navigator::previousSibling(Widget* widget)
{
    Widget* parent = current->parent();
    std::vector<Widget*> children = parent->children();
    short index = std::find(children.begin(), children.end(), widget) - children.begin() - 1;

    if (index < children.size() && index > -1)
    {
        return children[index];
    }
    else
    {
        return NULL;
    }
}

/**
 * Finds a next clickable widget with focus event
 * @return {Widget*} - if nothing found, then NULL
 */
Widget* Navigator::next()
{
    if (current == NULL)
    {
        current = root;
    }

    /**
     * @var {bool}    diving - indicates diving into widget subtree or bubbling out from it
     * @var {Widget*} diving - last focused widget
     **/
    bool diving = true;
    Widget* last = current;

    int which = 0;
    while (true)
    {
        Widget* next = NULL;
        if (current->parent() == NULL)
        {
            diving = true;
        }
        else
        {
            next = nextSibling(current);
        }

        if (diving && current->children().size())
        {
            current = current->children()[0];
            which = 0;
        }
        else if (next != NULL)
        {
            diving = true;
            current = next;
            which = 1;
        }
        else
        {
            diving = false;
            current = current->parent();
            which = 2;
        }

        if (current == last)
        {
            return current;
        }
        else if (diving && current->event(EVENT_FOCUS))
        {
            return current;
        }
    }

    return current;
}

/**
 * Finds a previous clickable widget with focus event
 * @return {Widget*} - if nothing found, then NULL
 */
Widget* Navigator::previous()
{
    if (current == NULL)
    {
        current = root;
    }

    /**
     * @var {bool}    diving - indicates diving into widget subtree or bubbling out from it
     * @var {Widget*} diving - last focused widget
     **/
    bool diving = false;
    Widget* last = current;

    int which = 0;
    while (true)
    {
        Widget* previous = NULL;
        if (current->parent() == NULL)
        {
            diving = true;
        }
        else
        {
            previous = previousSibling(current);
        }

        if (diving && current->children().size())
        {
            current = *(current->children().end() - 1);
            diving = current->children().size() ? true : false;
            which = 0;
        }
        else if (previous != NULL)
        {
            diving = current->children().size() ? true : false;
            current = previous;
            which = 1;
        }
        else
        {
            diving = false;
            current = current->parent();
            which = 2;
        }

        if (current == last)
        {
            return current;
        }
        else if (!diving && current->event(EVENT_FOCUS))
        {
            return current;
        }
    }

    return current;
}

/**
 * @constructor
 * @paran {Widget*} root - instance of the root widget (Console class)
 */
Navigator::Navigator(Widget* root) :
    current(NULL), root(root)
{}
