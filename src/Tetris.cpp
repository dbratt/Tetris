#include "Tetris.h"

Tetris::Tetris(int _Width, int _Height) :   gf(GameField(_Width, _Height)),
                                            screen(TetrisUI(_Width + 13.0, _Height + 2.0)),
                                            fig(Figure(Point(_Width / 2, 0 ))),
                                            nextFig(Figure(Point(_Width / 2, 0 ))),
                                            GameOver(false), RepeatGame(false),
                                            Score(0),
                                            oldScore(0),
                                            FPS(150.0) {}

void Tetris::OnKeyPressed(int btnCode)
{
    fig.Backup();

    switch (btnCode)
    {
    case KEY_LEFT:
        fig.moveLeft();
        break;

    case KEY_RIGHT:
        fig.moveRight();
        break;

    case KEY_DOWN:
        fig.moveDown();
        break;

    case KEY_ROTATE_LEFT:
        fig.rotateLeft();
        break;

    case KEY_ROTATE_RIGHT:
        fig.rotateRight();
        break;

    case KEY_ESCAPE:
        GameOver = true;
    default:
        break;
    }

    if(gf.hasColision(fig)) fig.Restore();
}

void Tetris::UpdateGame(double dt)
{
    int dScore = 0;
    fig.Backup();

    fig.Update(dt, FPS);

    if(gf.hasColision(fig))
    {
        fig.Restore();
        dScore = gf.Update(fig);
        Score += dScore;
        if(Score - oldScore > 1000)
        {
            oldScore = Score;
            if( FPS > 10.0) FPS -= 10.0;
        }
        if(gf.GameFieldFull()){
            GameOver = true;
        }
        fig = nextFig;
        nextFig = Figure(Point(gf.getWidthGameField() / 2, 0));
    }

    if(dScore > 0)
    {
        screen.showDestruction(gf, (int)dScore/250);
        screen.Render();
        Sleep(1000);
    }

    screen.Clear();

    screen.showGameField(gf);

    screen.showFigure(fig);

    screen.showGame(gf.getWidthGameField() + 2, gf.getHeightGameField() + 2);

    screen.showNextFigure(nextFig);

    screen.showScore(Score);

    if(GameOver)
    {
        for(int i = 0; i < 6; ++i)
        {
            screen.showFlicker(gf, i);
            screen.Render();
            Sleep(500);
        }

        RepeatGame = screen.showGameOver(Score);
    }

    screen.Render();
}

bool Tetris::EndGame()
{
    return GameOver;
}

bool Tetris::Repeat()
{
    return RepeatGame;
}
