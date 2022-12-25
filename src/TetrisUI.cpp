#include "TetrisUI.h"

TetrisUI::TetrisUI(int Width, int Height) : UI("Tetris", Width, Height),
                                            nameScore("SCORE:"),
                                            globCoordNameScore{Width - 9, 1},
                                            globCoordScore{Width - 9, 3},
                                            nameNextFigure("NEXT:"),
                                            globCoordNameNexFig{Width - 8, 5},
                                            globCoordNexFig{Width - 7, 7} {}


void TetrisUI::showGame(int widthFrame, int heightFrame){

    for(int ix = 0; ix < widthFrame; ++ix)
    {
        setSymbol(ix, 0, 219);
        setSymbol(ix, heightFrame - 1, 219);
    }

    for(int iy = 0; iy < heightFrame; ++iy)
    {
        setSymbol(0, iy, 219);
        setSymbol(widthFrame - 1, iy, 219); //177
    }

    for(int ix = 0; ix < nameScore.size(); ++ix)
    {
        setSymbol(globCoordNameScore.x + ix, globCoordNameScore.y, nameScore[ix]);
        setAttribute(globCoordNameScore.x + ix, globCoordNameScore.y, FOREGROUND_RED | FOREGROUND_GREEN);
    }

    for(int ix = 0; ix < nameNextFigure.size(); ++ix)
    {
        setSymbol(globCoordNameNexFig.x + ix, globCoordNameNexFig.y, nameNextFigure[ix]);
        setAttribute(globCoordNameNexFig.x + ix, globCoordNameNexFig.y, FOREGROUND_RED | FOREGROUND_GREEN);

    }
}

void TetrisUI::showGameField(GameField& gf)
{
    std::vector<std::vector<bool>> Cells = gf.getCells();

    std::vector<std::vector<WORD>> Colors = gf.getColors();

    for(int iy = 0; iy < Cells.size(); ++iy)
    {
        for(int ix = 0; ix < Cells[iy].size(); ++ix)
        {
            if (Cells[iy][ix])
            {
                setSymbol(ix + 1, iy + 1, '#');
                setAttribute(ix + 1, iy + 1, Colors[iy][ix]);
            }
        }
    }
}

void TetrisUI::showFigure(Figure & fig)
{
    Point globCoord = fig.getGlobCord();

    WORD color = fig.getColor();

    int ix, iy;

    for(const Point & point : fig.getShape())
    {
        ix = std::max(globCoord.x + point.x + 1, 1);
        iy = std::max(globCoord.y + point.y + 1, 1);
        setSymbol(ix, iy, '#');
        setAttribute(ix, iy, color);
    }
}

void TetrisUI::showNextFigure(Figure & fig)
{
    WORD color = fig.getColor();

    for(const Point & point : fig.getShape())
    {
        setSymbol(globCoordNexFig.x + point.x, globCoordNexFig.y + point.y + 1, '#');
        setAttribute(globCoordNexFig.x + point.x, globCoordNexFig.y + point.y + 1, color);
    }
}

void TetrisUI::showScore(int score)
{
    std::string strScore = std::to_string(score);

    for(int ix = 0; ix < strScore.size(); ++ix) setSymbol(globCoordScore.x + ix, globCoordScore.y, strScore[ix]);
}

bool TetrisUI::showGameOver(int score)
{
    Clear();
    std::string str = "Game Over. Your score: " + std::to_string(score);
    showStr(str, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, 0, 0);
    str = "Are you want to repeat? (y/n)";
    showStr(str, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, 0, 1);
    setCursorPosition(29, 1);
    Render();
    int resp = _getch();
    if (resp == 'y' || resp == 'Y') return true;
    else return false;
}


void TetrisUI::showFlicker(GameField& gf, int i)
{
    std::vector<std::vector<bool>> Cells = gf.getCells();

    std::vector<std::vector<WORD>> Colors = gf.getColors();

    for(int iy = 0; iy < Cells.size(); ++iy)
    {
        for(int ix = 0; ix < Cells[iy].size(); ++ix)
        {
            if (Cells[iy][ix])
            {
                if(i%2) setAttribute(ix + 1, iy + 1, Colors[iy][ix]);
                else setAttribute(ix + 1, iy + 1, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
        }
    }
}

void TetrisUI::showDestruction(GameField& gf, int k)
{
    std::vector<std::vector<bool>> Cells = gf.getCells();

    std::vector<std::vector<WORD>> Colors = gf.getColors();

    for(int iy = Cells.size() - 1; iy > Cells.size() - 2 - k; --iy)
    {
        for(int ix = 0; ix < Cells[iy].size(); ++ix) setAttribute(ix + 1, iy + 1, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
}
