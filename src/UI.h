#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <windows.h>

class UI{

    public:
        UI(LPCSTR title, int Width, int Height);
        ~UI();
        void Render();
        void Clear();
        void setCursorPosition(int x, int y);
        void showCursor(bool visible);
        void showStr(std::string str, WORD attr, int x, int y);

    protected:
        void setSymbol(int ix, int iy, wchar_t c);
        void setAttribute(int ix, int iy, WORD attr);

    private:
        HANDLE hConsoleOut;
        CHAR_INFO* Buffer = nullptr;
	    COORD BufferSize;
	    COORD BufferCoord;
        SMALL_RECT WriteRegion;
};
