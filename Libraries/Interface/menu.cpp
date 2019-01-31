/**
 * EAdds button to the menu
 * @param {const char*} name - text drawn at the button
 */
void Menu::addButton(const char* name)
{
    buttons.push_back({name});
}

/**
 * Event listener activated by Navigator module when user selects on widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::focus(int index)
{
    move(y + index * 2 + 1, x);
    printw(">");
}

/**
 * Event listener activated by Navigator module when user removes selection from widget
 * @override
 * @callback Navigator::listener
 * @param {int} index - index of subunit of the widget
 */
void Menu::unfocus(int index)
{
    move(y + index * 2 + 1, x);
    printw(" ");
}

/**
 * Draws Menu in console window
 */
void Menu::draw()
{
    int yCounter = y + 1;

    for (list<MenuButton>::iterator currentButton = buttons.begin(); currentButton != buttons.end(); currentButton++)
    {
        move(yCounter, x + (2 + width - strlen(currentButton->name)) / 2);
        printw(currentButton->name);
        yCounter += 2;
    }
}

/**
 * @constructor
 * @param {int} x      - x coordinate of left menu side
 * @param {int} y      - y coordinate of top menu side
 * @param {int} width  - menu width
 * @param {int} height - menu height
 */
Menu::Menu(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{}
