#include "GameField.h"

GameField::GameField(int _Width, int _Height) : Width(_Width), Height(_Height)
{
    Cells = std::vector<std::vector<bool>>(Height, std::vector<bool>(Width, false));
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

bool GameField::hasColision(Figure & fig){

    Point globCoord = fig.getGlobCord();

    for(const Point & point : fig.getShape()){
        if(globCoord.x + point.x < 0 || globCoord.x + point.x > Width - 1) return true;
        if(globCoord.y + point.y < -2 || globCoord.y + point.y > Height - 1) return true;
        if(Cells.at(std::max(0, globCoord.y + point.y)).at(std::max(0, globCoord.x + point.x))) return true;
    }

    return false;
}

bool GameField::GameFieldFull(){
    for(int ix = 0; ix < Width; ++ix) if(Cells[0][ix]) return true;
    return false;
}


void GameField::Update(Figure& fig){

    Point globCoord = fig.getGlobCord();

    for(const Point& point : fig.getShape()){
        Cells.at(std::max(0, globCoord.y + point.y)).at(std::max(0, globCoord.x + point.x)) = true;
    }

    bool filled;

    for(int iy = 0; iy < Cells.size(); ++iy){

        filled = true;

        for(int ix = 0; ix < Cells[iy].size(); ++ix){
            filled = filled && Cells[iy][ix];
        }

        if(filled){
            for(int k = iy; k > 0; --k){
                Cells[k] = Cells[k - 1];
            }
            Cells[0] = std::vector<bool>(Width, false);
        }
    }
}
