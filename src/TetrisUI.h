#pragma once

#include <conio.h>
#include "Figure.h"
#include "GameField.h"
#include "UI.h"

class TetrisUI : public UI
{
    public:
        TetrisUI(int Width, int Height);

        void showGameField(GameField& gf);

        void showFigure(Figure& fig);

        void showNextFigure(Figure& fig);

        void showGame(int widthFrame, int heightFrame);

        void showScore(int score);

        bool showGameOver(int score);

        void showFlicker(GameField& gf, int i);

        void showDestruction(GameField& gf, int i);

    private:
        std::string nameScore;
        Point globCoordNameScore;
        Point globCoordScore;
        std::string nameNextFigure;
        Point globCoordNameNexFig;
        Point globCoordNexFig;
};
