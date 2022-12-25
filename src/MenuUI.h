#pragma once

#include "UI.h"
#include <vector>

//using function = void (*)();

typedef struct
{
    int x, y;
    std::string name;
    WORD isActive;
    //function f;
} Item;

class MenuUI : public UI
{

public:
    MenuUI(int _Width, int _Height);

    void showMenu(std::vector<Item> menu);
};
