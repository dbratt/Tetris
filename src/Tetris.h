#pragma once

#include "Game.h"
#include "TetrisUI.h"

#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_DOWN 115
#define KEY_ROTATE_LEFT 113
#define KEY_ROTATE_RIGHT 101
#define KEY_ESCAPE 27

class Tetris : public Game
{
public:
    Tetris(int _Width, int _Height);
    ~Tetris() = default;

private:
    GameField gf;
    TetrisUI screen;
    Figure fig;
    Figure nextFig;
    bool GameOver;
    bool RepeatGame;
    int Score;
    int oldScore;
    double FPS;

    void OnKeyPressed(int btnCode) override;
    void UpdateGame(double dt) override;
    bool EndGame() override;
    bool Repeat() override;
};
