void Menu::addButton(const char* name)
{
    buttons.push_back({name});
}

void Menu::focus(int index)
{
    move(y + index * 2 + 1, x);
    printw(">");
}

void Menu::unfocus(int index)
{
    move(y + index * 2 + 1, x);
    printw(" ");
}

void Menu::draw()
{
    int xCounter = x + 2;
    int yCounter = y + 1;
    move(yCounter, xCounter);

    for (list<MenuButton>::iterator currentButton = buttons.begin(); currentButton != buttons.end(); currentButton++)
    {
        printw(currentButton->name);
        yCounter += 2;
        move(yCounter, xCounter);
    }
}

Menu::Menu(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{
    border = 1;
}
