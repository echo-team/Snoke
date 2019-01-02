#include <list>

using namespace std;

typedef struct
{
    const char* name;
} MenuButton;

class Menu : public Widget
{
    private:
        list<MenuButton> buttons;
        int border;
        int x, y, width, height;

    public:
        void addButton(const char* name);
        void focus(int index);
        void unfocus(int index);
        void draw();
        Menu(int x, int y, int width, int height);
};

#include "menu.cpp"
