#pragma once

#define FIELD_WIDTH 10;
#define FIELD_HEIGHT 20;
#include <vector>
#include <algorithm>
#include "Figure.h"

class GameField{

public:
    GameField(int _Width, int _Height);

    int getWidthGameField() const;

    int getHeightGameField() const;

    std::vector<std::vector<bool>> getCells();

    std::vector<std::vector<WORD>> getColors();

    bool hasColision(Figure& fig);

    int Update(Figure& fig);

    bool GameFieldFull();


private:
    int Width;
    int Height;
    std::vector<std::vector<bool>> Cells;
    std::vector<std::vector<WORD>> Colors;

};
