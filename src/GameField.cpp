#include "GameField.h"

GameField::GameField(int _Width, int _Height) : Width(_Width), Height(_Height)
{
    Cells = std::vector<std::vector<bool>>(Height, std::vector<bool>(Width, false));

    Colors = std::vector<std::vector<WORD>>(Height, std::vector<WORD>(Width, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY));
}

int GameField::getWidthGameField() const
{
    return Width;
}

int GameField::getHeightGameField() const
{
    return Height;
}

std::vector<std::vector<bool>> GameField::getCells()
{
    return Cells;
}

std::vector<std::vector<WORD>> GameField::getColors()
{
    return Colors;
}


bool GameField::hasColision(Figure & fig){

    Point globCoord = fig.getGlobCord();

    for(const Point & point : fig.getShape()){
        if(globCoord.x + point.x < 0 || globCoord.x + point.x > Width - 1) return true;
        if(/*globCoord.y + point.y < -2 ||*/ globCoord.y + point.y > Height - 1) return true;
        if(Cells.at(std::max(0, globCoord.y + point.y)).at(std::max(0, globCoord.x + point.x))) return true;
    }

    return false;
}

bool GameField::GameFieldFull()
{
    for(int ix = 0; ix < Width; ++ix) if(Cells[0][ix]) return true;
    return false;
}


int GameField::Update(Figure& fig)
{
    Point globCoord = fig.getGlobCord();

    WORD color = fig.getColor();

    for(const Point& point : fig.getShape())
    {
        Cells.at(std::max(0, globCoord.y + point.y)).at(std::max(0, globCoord.x + point.x)) = true;
        Colors.at(std::max(0, globCoord.y + point.y)).at(std::max(0, globCoord.x + point.x)) = color;
    }

    bool filled;

    int score = 0;

    int count = 0;

    for(int iy = 0; iy < Cells.size(); ++iy)
    {
        filled = true;

        for(int ix = 0; ix < Cells[iy].size(); ++ix) filled = filled && Cells[iy][ix];

        if(filled)
        {
            count++;
            score += 100 * count;

            for(int k = iy; k > 0; --k)
            {
                Cells[k] = Cells[k - 1];
                Colors[k] = Colors[k - 1];
            }

            Cells[0] = std::vector<bool>(Width, false);
            Colors[0] = std::vector<WORD>(Width, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
    }

    return score;
}
