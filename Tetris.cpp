#include "Tetris.h"

Tetris::Tetris() : gf(GameField()), screen(UI(gf.getWidthGameField(), gf.getHeightGameField())),  fig(Figure()){
    
}

void Tetris::OnKeyPressed(int btnCode){

}

void Tetris::UpdateGame(double dt){

    screen.Clear();

    fig.Update(dt);

    screen.showGameField(gf.getWidthGameField(), gf.getHeightGameField());

    screen.showFigure(gf.getWidthGameField(), gf.getHeightGameField());

    screen.Render();

    end_game=1;

}

bool Tetris::EndGame(){
    return end_game;
}