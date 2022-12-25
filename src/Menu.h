#include "MenuUI.h"
#include "Tetris.h"

#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13

#define ACTIVE BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
#define NONACTIVE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY

enum menuItem {START, SETTING, EXIT};

class Menu
{
public:
    Menu(int _Width=30, int _Height=25);

    void Open();

private:

    int Width;
    int Height;
    int TetrisWidth;
    int TetrisHeight;
    int numItem;
    menuItem curItem;
    std::vector<Item> menu;
    MenuUI screen;

    void Start();
    void Setting();
    void Exit();
};
