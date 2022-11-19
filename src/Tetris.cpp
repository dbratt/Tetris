#include "Tetris.h"

Tetris::Tetris() :  gf(GameField()),
                    screen(UI(gf.getWidthGameField(), gf.getHeightGameField())),
                    fig(Figure(Point(gf.getWidthGameField() / 2, 0 ))),
                    GameOver(false) {}

void Tetris::OnKeyPressed(int btnCode){

    fig.Backup();

    switch (btnCode)
    {
    case 97:
        fig.moveLeft();
        break;

    case 100:
        fig.moveRight();
        break;

    case 115:
        fig.moveDown();
        break;

    case 113:
        fig.rotateLeft();
        break;

    case 101:
        fig.rotateRight();
        break;

    default:
        break;
    }

    if(gf.hasColision(fig)) fig.Restore();
}

void Tetris::UpdateGame(double dt){

    fig.Backup();

    fig.Update(dt);

    if(gf.hasColision(fig)){
        fig.Restore();
        gf.Update(fig);
        if(gf.GameFieldFull()){
            GameOver = true;
            return;
        }
        fig = Figure(Point(gf.getWidthGameField() / 2, 0));
        //if(gf.hasColision(fig)) GameOver = true;
    }

    screen.Clear();

    screen.showGameField(gf);

    screen.showFigure(fig);

    screen.showGame(gf.getWidthGameField() + 2, gf.getHeightGameField() + 2);

    screen.Render();
}

bool Tetris::EndGame(){
    return GameOver;
}
