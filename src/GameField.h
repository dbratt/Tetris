#pragma once

#define FIELD_WIDTH 10;
#define FIELD_HEIGHT 20;
#include <vector>
#include <algorithm>
#include "Figure.h"

class GameField{

public:
    GameField(int _Width=15, int _Height=20);

    int getWidthGameField() const;

    int getHeightGameField() const;

    std::vector<std::vector<bool>> getCells();

    bool hasColision(Figure& fig);

    void Update(Figure& fig);

    bool GameFieldFull();


private:
    int Width;
    int Height;
    std::vector<std::vector<bool>> Cells;

};
