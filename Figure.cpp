#include "Figure.h"

Figure::Figure(){
    Shape = rand() % 6;
    
    Rotation = rand() % 3;
}


bool Figure::getFigureCell(unsigned ix, unsigned iy){
    return FigureShapes[Shape][Rotation][ix][iy];
}

int Figure::getInitialXDisplacement(){
    return FigureInitialDiscplacement[Shape][Rotation][0];
}

int Figure::getInitialYDisplacement(){
    return FigureInitialDiscplacement[Shape][Rotation][1];
}

int Figure::getFigureXGlobCord(){
    return xGlobCord;
}

int Figure::getFigureYGlobCord(){
    return yGlobCord;
}

void Figure::Update(){
    
}