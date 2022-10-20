#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <windows.h>

class UI{

public:
    UI(int widthGF, int heightGF, int Width=30, int Height=40);

    ~UI();

    void showGameField(int widthGameField, int heightGameField);

    void showFigure(int xGlob, int yGlob);

    void Render();

    void Clear();

private:

    HANDLE hConsoleOut; 
    CHAR_INFO* Buffer = nullptr;
	COORD BufferSize;
	COORD BufferCoord;
    SMALL_RECT WriteRegion;

    void setSymbol(int ix, int iy, wchar_t c);
};