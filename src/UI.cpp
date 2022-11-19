#include "UI.h"

UI::UI(int widthGF, int heightGF, int Width, int Height) : BufferCoord{0, 0},
                                                           BufferSize{static_cast<SHORT>(Width), static_cast<SHORT>(Height)},
                                                           GFSize{static_cast<SHORT>(widthGF), static_cast<SHORT>(heightGF)},
                                                           WriteRegion{static_cast<SHORT>(0), static_cast<SHORT>(0), static_cast<SHORT>(Width - 1), static_cast<SHORT>(Height - 1)}
{

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

    //Clear();
}

UI::~UI(){
    delete[] Buffer;
}


void UI::setSymbol(int ix, int iy, wchar_t c){
    Buffer[ix + iy * BufferSize.X].Char.UnicodeChar = c;
}

void UI::setAttribute(int ix, int iy, WORD attr){
    Buffer[ix + iy * BufferSize.X].Attributes = attr;
}

void UI::Render(){
	if (!WriteConsoleOutput(hConsoleOut, Buffer, BufferSize, BufferCoord, &WriteRegion))
		std::cout << __LINE__ << ": WriteConsoleOutput failed - (%d)\n" << GetLastError() << std::endl;
}

void UI::Clear(){
    //SetConsoleCursorPosition(hConsoleOut, BufferCoord);
    for(int ix = 0; ix != BufferSize.X; ++ix){
        for(int iy = 0; iy != BufferSize.Y; ++iy){
            setSymbol(ix, iy, ' ');
            setAttribute(ix, iy, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
    }
}

void UI::showGame(int widthFrame, int heightFrame){

    for(int ix = 0; ix != widthFrame; ++ix){
        setSymbol(ix, 0, 177);
        setSymbol(ix, heightFrame-1, 177);
    }

    for(int iy = 0; iy != heightFrame; ++iy){
        setSymbol(0, iy, 177);
        setSymbol(widthFrame-1, iy, 177);
    }
}

void UI::showGameField(GameField& gf){

    std::vector<std::vector<bool>> Cells = gf.getCells();

    for(int iy = 0; iy != Cells.size(); ++iy){
        for(int ix = 0; ix != Cells[iy].size(); ++ix){
            if (Cells[iy][ix]==true) setSymbol(ix + 1, iy + 1, '#');
        }
    }
}

void UI::showFigure(Figure & fig){

    Point globCoord = fig.getGlobCord();

    for(const Point & point : fig.getShape()){
        setSymbol(globCoord.x + point.x + 1, globCoord.y + point.y + 1, '#');
    }

}


// биндинг лямбда функций, область захвата []()->type
