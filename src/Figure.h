#pragma once

#include <cstdlib>
#include <vector>
#include <windows.h>
#include <iostream>

struct Point
{
    Point (int _x, int _y) : x(_x), y(_y) {}

    int x;
    int y;
};

class Figure{

    public:
        Figure(Point _globCoord);

        Point getGlobCord();

        std::vector<Point> getShape();

        WORD getColor();

        void Update(double dt, double FPS);

        void moveLeft();

        void moveRight();

        void moveDown();

        void rotateLeft();

        void rotateRight();

        void Backup();

        void Restore();

    private:
        Point globCoord;
        Point globCoordOld;
        std::vector<std::vector<Point>> Shape;
        WORD Color;
        int Rotation;
        int RotationOld;

        double currentTime;

        std::vector<std::vector<Point>> GenerateShape();

        WORD GenerateColor();

};
