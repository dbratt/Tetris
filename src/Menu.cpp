#include "Menu.h"

Menu::Menu(int _Width, int _Height) :   Width(_Width), Height(_Height),
                                        TetrisWidth(17), TetrisHeight(23),
                                        numItem(3), curItem(START),
                                        menu({
                                                {_Width/3, _Height/3, " Start ", ACTIVE},
                                                {_Width/3, _Height/3 + 1, " Setting ", NONACTIVE},
                                                {_Width/3, _Height/3 + 2, " Exit  ", NONACTIVE}
                                            }),
                                        screen(_Width, _Height) {}


void Menu::Open()
{
    while(true)
    {
        screen.Clear();

        if (_kbhit())
        {
            switch (_getch())
            {
                case KEY_ARROW_DOWN:
                    if (curItem < numItem - 1)
                    {
                        menu[curItem].isActive = NONACTIVE;
                        curItem = (menuItem)(curItem + 1);
                        menu[curItem].isActive = ACTIVE;
                    }
                    else
                    {
                        menu[curItem].isActive = NONACTIVE;
                        curItem = (menuItem)(0);
                        menu[curItem].isActive = ACTIVE;
                    }
                    break;
                case KEY_ARROW_UP:
                    if (curItem > 0)
                    {
                        menu[curItem].isActive = NONACTIVE;
                        curItem = (menuItem)(curItem - 1);
                        menu[curItem].isActive = ACTIVE;
                    }
                    else
                    {
                        menu[curItem].isActive = NONACTIVE;
                        curItem = (menuItem)(numItem - 1);
                        menu[curItem].isActive = ACTIVE;
                    }
                    break;
                case KEY_ENTER:
                    switch(curItem)
                    {
                        case START:
                            Start();
                            SetConsoleTitle("Menu");
                            break;
                        case SETTING:
                            Setting();
                            break;
                        case EXIT:
                            Exit();
                            break;
                    }
                    break;
                case KEY_ESCAPE:
                    exit(0);
                    break;
            }
        }

        screen.showMenu(menu);

        screen.Render();
    }
}

void Menu::Start()
{
    srand(time(0));
    bool repeat = true;
    while(repeat)
    {
        Tetris tetris(TetrisWidth, TetrisHeight);
        repeat = tetris.Run();
    }
}

void Menu::Setting()
{
    screen.Clear();
    screen.showCursor(true);
    screen.showStr("Input size game field: ", NONACTIVE, 1, 0);
    screen.showStr("Width = ", NONACTIVE, 1, 1);
    screen.showStr("Height = ", NONACTIVE, 1, 2);
    screen.Render();
    screen.setCursorPosition(9, 1);
    std::cin >> TetrisWidth;
    screen.setCursorPosition(10, 2);
    std::cin >> TetrisHeight;
}

void Menu::Exit()
{
    screen.Clear();
    screen.showStr("Are you want to exit? (y/n)", NONACTIVE, 0, Height/2);
    screen.Render();
    int resp = _getch();
    if (resp == 'y' || resp == 'Y') exit(0);
}
