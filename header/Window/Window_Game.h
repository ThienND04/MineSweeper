#ifndef WINDOW_GAME_H
#define WINDOW_GAME_H

#include <Window.h>
#include <Game.h>
#include <Button.h>
#include <EventReceiver.h>
#include <TextureCreator.h>

class WindowGame : public Window {
public:
    static WindowGame *getInstance();

    WindowGame(Game *game);
    ~WindowGame();

private:
    int gridSize;
    static WindowGame *instance;
    Game *game;

public:
    Game *getGame() {return game; };
    int getGridSize() {return gridSize; }
    int setGridSize(int gridSize) {this->gridSize = gridSize; }
};

#endif