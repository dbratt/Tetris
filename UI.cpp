#include "UI.h"


UI::UI(int widthGF, int heightGF, int Width, int Height) : BufferCoord{0, 0}, BufferSize{(SHORT)Width, (SHORT)Height}, WriteRegion{(SHORT)0, (SHORT)0, (SHORT)(Width - 1), (SHORT)(Height - 1)}{

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTitle("Tetris");

    /* Задание координат консольного окна */
    if (!SetConsoleWindowInfo(hConsoleOut, TRUE, &WriteRegion)) {
		std::cout << __LINE__ << ": SetConsoleWindowInfo failed with error " << GetLastError() << std::endl;
		return;
	}

    /* Задание размеров буфера окна консоли */
    if (!SetConsoleScreenBufferSize(hConsoleOut, BufferSize)) {
		std::cout << __LINE__ << ": SetConsoleScreenBufferSize failed with error " << GetLastError() << std::endl;
		return;
    }

    Buffer = new CHAR_INFO[Width*Height];

    for(int ix=0; ix!=widthGF; ++ix){
        setSymbol(ix,0,'-'/*0x035E*/);
        setSymbol(ix,heightGF,'_'/*0x035F*/);
    }

    for(int iy=0; iy!=heightGF; ++iy){
        setSymbol(0,iy,'|'/*0x007C*/);
        setSymbol(widthGF,iy,'|'/*0x007C*/);
    }

}

UI::~UI(){
    delete [] Buffer;
}

void UI::showGameField(int widthGameField, int heightGameField){

}

void UI::showFigure(int xGlob, int yGlob){



}


void UI::setSymbol(int ix, int iy, wchar_t c){
    Buffer[ix + iy * BufferSize.X].Char.UnicodeChar = c;
}

void UI::Render(){
    std::cout<<5;
	if (!WriteConsoleOutput(hConsoleOut, Buffer, BufferSize, BufferCoord, &WriteRegion))
		std::cout << __LINE__ << ": WriteConsoleOutput failed - (%d)\n" << GetLastError() << std::endl;
}

void UI::Clear(){
    SetConsoleCursorPosition(hConsoleOut, BufferCoord);
    FillConsoleOutputCharacter(hConsoleOut,(TCHAR)' ', BufferSize.X * BufferSize.Y, BufferCoord, nullptr);
    SetConsoleCursorPosition(hConsoleOut, BufferCoord);
}


// биндинг лямбда функций, область захвата []()->type