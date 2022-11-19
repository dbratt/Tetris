#pragma once

#include <cstdlib>
#include <vector>

struct Point{

    Point (int _x, int _y) : x(_x), y(_y) {}

    int x;
    int y;
};

class Figure{

    public:
        Figure(Point _globCoord);

        Point getGlobCord();

        std::vector<Point> getShape();

        void Update(double dt);

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
        int Rotation;
        int RotationOld;

        double currentTime;
        double FPS = 150;

        std::vector<std::vector<Point>> Generate();
};
