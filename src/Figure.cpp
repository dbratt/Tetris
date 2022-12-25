#include "Figure.h"

Figure::Figure(Point _globCoord) : globCoord(_globCoord), globCoordOld(_globCoord)
{
    Shape = GenerateShape();

    Color = GenerateColor();

    Rotation = rand() % Shape.size();

    //RotationOld = Rotation;
}

Point Figure::getGlobCord()
{
    return globCoord;
}

std::vector<Point> Figure::getShape()
{
    return Shape[Rotation];
}

WORD Figure::getColor()
{
    return Color;
}

void Figure::Update(double dt, double FPS)
{
    currentTime += dt;
    if(currentTime > FPS)
    {
        currentTime = 0.0;
        ++globCoord.y;
    }
}

void Figure::moveLeft()
{
    --globCoord.x;
}

void Figure::moveRight()
{
    ++globCoord.x;
}

void Figure::moveDown()
{
    ++globCoord.y;
}

void Figure::rotateLeft()
{
    --Rotation;
    if (Rotation < 0) Rotation = Shape.size()-1;
}

void Figure::rotateRight()
{
    ++Rotation;
    if (Rotation >= Shape.size()) Rotation = 0;
}

void Figure::Backup()
{
    globCoordOld = globCoord;
    RotationOld = Rotation;
}

void Figure::Restore()
{
    globCoord = globCoordOld;
    Rotation = RotationOld;
}

std::vector<std::vector<Point>> Figure::GenerateShape()
{
    switch(rand() % 7)
    {
        case 0: return { // I
                        {Point(-1, 0), Point(0, 0), Point(1, 0), Point(2, 0)},
                        {Point(0, -1), Point(0, 0), Point(0, 1), Point(0, 2)},
                        {Point(-2, 0), Point(-1, 0), Point(0, 0), Point(1, 0)},
                        {Point(0, -2), Point(0, -1), Point(0, 0), Point(0, 1)},
                       };
        case 1: return { // L
                        {Point(-1, 1), Point(-1, 0), Point(0, 0), Point(1, 0)},
                        {Point(-1, -1), Point(0, -1), Point(0, 0), Point(0, 1)},
                        {Point(-1, 0), Point(0, 0), Point(1, 0), Point(1, -1)},
                        {Point(0, -1), Point(0, 0), Point(0, 1), Point(1, 1)},
                       };
        case 2: return { // L-mirrored
                        {Point(-1, -1), Point(-1, 0), Point(0, 0), Point(1, 0)},
                        {Point(0, 1), Point(0, 0), Point(0, -1), Point(1, -1)},
                        {Point(-1, 0), Point(0, 0), Point(1, 0), Point(1, 1)},
                        {Point(-1, 1), Point(0, 1), Point(0, 0), Point(0, -1)},
                       };
        case 3: return { // Z
                        {Point(-1, 0), Point(0, 0), Point(0, 1), Point(1, 1)},
                        {Point(-1, 1), Point(-1, 0), Point(0, 0), Point(0, -1)},
                        {Point(-1, -1), Point(0, -1), Point(0, 0), Point(1, 0)},
                        {Point(0, 1), Point(0, 0), Point(1, 0), Point(1, -1)},
                       };
        case 4: return { // Z-mirroed
                        {Point(-1, 1), Point(0, 1), Point(0, 0), Point(1, 0)},
                        {Point(-1, -1), Point(-1, 0), Point(0, 0), Point(0, 1)},
                        {Point(-1, 0), Point(0, 0), Point(0, -1), Point(1, -1)},
                        {Point(0, -1), Point(0, 0), Point(1, 0), Point(1, 1)},
                       };
        case 5: return { // T
                        {Point(-1, 0), Point(0, 0), Point(1, 0), Point(0, 1)},
                        {Point(-1, 0), Point(0, 0), Point(0, -1), Point(0, 1)},
                        {Point(-1, 0), Point(0, 0), Point(1, 0), Point(0, -1)},
                        {Point(0, 0), Point(1, 0), Point(0, -1), Point(0, 1)},
                       };
        case 6: return { // Q
                        {Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1)}
                       };
    }
}

WORD Figure::GenerateColor()
{
    switch(rand() % 6)
    {
        case 0: return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case 1: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case 2: return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case 3: return  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case 4: return  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case 5: return  FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    }
}
