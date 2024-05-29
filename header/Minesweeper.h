#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <Window.h>
#include <GameController.h>

class Minesweeper{
public:
    static const int FPS = 60;

    bool init();
    void exit();
    void start();

private:
    Window* window = NULL;
    GameController *gameController = NULL;
};

#endif