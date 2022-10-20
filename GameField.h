#define FIELD_WIDTH 10;
#define FIELD_HEIGHT 20;
#include "BoolMatrix.cpp"

class GameField{

public:
    GameField(int _Width=15, int _Height=20);

    int getWidthGameField() const;

    int getHeightGameField() const;


private:
    int Width;
    int Height;
    BoolMatrix *Cells;

};