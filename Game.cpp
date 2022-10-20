#include "Game.h"
#include <conio.h>

void Game::Run(){

    Time last = Clock::now();

    while(!EndGame()){

        if(_kbhit()){

            OnKeyPressed(_getch());
        }

        UpdateGame(static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - last).count()));

        last = Clock::now();

    }
}