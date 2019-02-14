#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <ncurses.h>
#include <list>
#include "interface.h"

/**
 * Describes selectable/interactive widget or the group of widgets
 * @prop {Widget*} widget         - selectable widget class
 * @prop {int}     subunitsAmount - amount of user actions to move to another widget (e.g: amount of subwidgets or lines in the scrollbox)
 */
typedef struct
{
    Widget* widget;
    int subunitsAmount;
} NavigateUnit;

/**
 * Adds an ability to select/activate widgets
 * @prop {list<NavigateUnit>}           units          - widgets/groups of widgets which can be selected
 * @prop {list<NavigateUnit>::iterator} currentUnit    - selected widget
 * @prop {int}                          currentSubunit - number of subwidget
 */
class Navigator
{
    private:
        std::list<NavigateUnit> units;
        std::list<NavigateUnit>::iterator currentUnit;
        int currentSubunit;

    public:
        void pushUnit(Widget* unit, int subunitsAmount);
        void listen();
        Navigator();
};

#endif
