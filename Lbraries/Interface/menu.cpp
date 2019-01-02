void Menu::addButton(const char* name)
{
    buttons.push_back({name});
}

void Menu::draw()
{
    x += 2;
    y += 1;
    move(y, x);

    for (list<MenuButton>::iterator currentButton = buttons.begin(); currentButton != buttons.end(); currentButton++)
    {
        printw(currentButton->name);
        y += 2;
        move(y, x);
    }
}

Menu::Menu(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{
    border = 1;
}
