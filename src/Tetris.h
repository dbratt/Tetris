#include "Game.h"
//#include "GameField.h"
//#include "Figure.h"
#include "UI.h"

class Tetris : public Game{

public:
    Tetris();
    ~Tetris() = default;

private:
    GameField gf;
    UI screen;
    Figure fig;
    bool GameOver;

    void OnKeyPressed(int btnCode) override;
    void UpdateGame(double dt) override;
    bool EndGame() override;

};
