#include "MenuUI.h"

MenuUI::MenuUI(int Width, int Height) : UI("Menu", Width, Height) {}


void MenuUI::showMenu(std::vector<Item> menu)
{
    showStr(" T E T R I S ", FOREGROUND_GREEN | FOREGROUND_RED , menu[0].x - 3, menu[0].y - 3);
    for(const Item & item : menu) showStr(item.name, item.isActive, item.x, item.y);
}
