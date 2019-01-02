typedef struct
{
    Widget* widget;
    int subunitsAmount;
} NavigateUnit;

class Navigator
{
    private:
        list<NavigateUnit> units;
        list<NavigateUnit>::iterator currentUnit;
        int currentSubunit;

    public:
        void pushUnit(Widget* unit, int subunitsAmount);
        void listen();
        Navigator();
};

#include "navigator.cpp"
