#include <cstring>
#include <list>

/**
 * Describes menu button
 * @prop {const char*} name - text drawn at the button
 */
typedef struct
{
    const char* name;
} MenuButton;

/**
 * Menu (list of selestable items) widget class
 * @prop  {list<MenuButton>} buttons - buttons included in menu
 * @prop {int}              x       - x coordinate of left menu side
 * @prop {int}              y       - y coordinate of top menu side
 * @prop {int}              width   - menu width
 * @prop {int}              height  - menu height
 */
class Menu : public Widget
{
    private:
        std::list<MenuButton> buttons;
        int x, y, width, height;

    public:
        void addButton(const char* name);
        void focus(int index);
        void unfocus(int index);
        void draw();
        Menu(int x, int y, int width, int height);
};

#include "menu.cpp"
