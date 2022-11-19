#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Figure.h"
#include "GameField.h"

class UI{

    public:
        UI(int widthGF, int heightGF, int Width=30, int Height=25);

        ~UI();

        void showGameField(GameField& gf);

        void showFigure(Figure& fig);

        void showGame(int widthFrame, int heightFrame);

        void Render();

        void Clear();

    private:
        HANDLE hConsoleOut;
        CHAR_INFO* Buffer = nullptr;
	    COORD BufferSize;
        COORD GFSize;
	    COORD BufferCoord;
        SMALL_RECT WriteRegion;

        void setSymbol(int ix, int iy, wchar_t c);

        void setAttribute(int ix, int iy, WORD attr);

};
