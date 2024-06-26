#ifndef WINDOW_GAME_H
#define WINDOW_GAME_H

#include <Window.h>
#include <Game.h>
#include <Button.h>
#include <EventReceiver.h>
#include <TextureCreator.h>

class WindowGame : public Window {
public:
    WindowGame(Game *game);
    ~WindowGame();

private:
    int gridSize;
    Game *game;

public:
    Game *getGame() {return game; };
    int getGridSize() {return gridSize; }
    int setGridSize(int gridSize) {this->gridSize = gridSize; }
};

#endif