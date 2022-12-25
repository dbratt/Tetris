#pragma once

#include <chrono>
#include <conio.h>
#include <iostream>
#include <vector>
#include "UI.h"

class Game
{
public:
    virtual ~Game() = default;
    bool Run();

private:
    virtual void OnKeyPressed(int btnCode) = 0;
    virtual void UpdateGame(double dt) = 0;
    virtual bool EndGame() = 0;
    virtual bool Repeat() = 0;

    using Clock = std::chrono::system_clock;
    using Time = std::chrono::time_point<Clock>;
};
