#include "UI.h"

UI::UI(LPCSTR title, int Width, int Height) : BufferCoord{0, 0},
                                              BufferSize{static_cast<SHORT>(Width), static_cast<SHORT>(Height)},
                                              WriteRegion{static_cast<SHORT>(0), static_cast<SHORT>(0), static_cast<SHORT>(Width - 1), static_cast<SHORT>(Height - 1)}
{
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTitle(title);

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

    showCursor(false);
}

UI::~UI()
{
    delete[] Buffer;
}


void UI::setSymbol(int ix, int iy, wchar_t c)
{
    Buffer[ix + iy * BufferSize.X].Char.UnicodeChar = c;
}

void UI::setAttribute(int ix, int iy, WORD attr)
{
    Buffer[ix + iy * BufferSize.X].Attributes = attr;
}

void UI::Render()
{
	if (!WriteConsoleOutput(hConsoleOut, Buffer, BufferSize, BufferCoord, &WriteRegion))
		std::cout << __LINE__ << ": WriteConsoleOutput failed - (%d)\n" << GetLastError() << std::endl;
}

void UI::Clear()
{
    for(int ix = 0; ix != BufferSize.X; ++ix)
    {
        for(int iy = 0; iy != BufferSize.Y; ++iy)
        {
            setSymbol(ix, iy, ' ');
            setAttribute(ix, iy, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
    }

    SetConsoleCursorPosition(hConsoleOut, BufferCoord);
    showCursor(false);
}

void UI::setCursorPosition(int x, int y)
{
    COORD cursorPos = {x, y};
    SetConsoleCursorPosition(hConsoleOut, cursorPos);
}

void UI::showCursor(bool visible)
{
    CONSOLE_CURSOR_INFO ccInfo;
    ccInfo.bVisible = visible;
    SetConsoleCursorInfo(hConsoleOut, &ccInfo);
}

void UI::showStr(std::string str, WORD attr, int x, int y)
{
    for(int i = 0; i < str.size(); ++i)
    {
        setSymbol(i + x, y, str[i]);
        setAttribute(i + x, y, attr);
    }
}
