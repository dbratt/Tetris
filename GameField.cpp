#include "GameField.h"

GameField::GameField(int _Width, int _Height) : Width(_Width), Height(_Height) {
    Cells = new BoolMatrix(Width, Height);
}

int GameField::getWidthGameField() const{
    return Width;
}

int GameField::getHeightGameField() const{
    return Height;
}