#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

// class Controller;

#include <Controller.h>
#include <Window_Game.h>
#include <Game.h>
#include <Button.h>
#include <EventReceiver.h>
#include <TextureCreator.h>
#include <vector>
#include <enums.h>
#include <string>
#include <Box.h>
#include <Text.h>
#include <Minesweeper.h>

class GameController: public Controller {
public:
    static GameController *getInstance();

    void updateGUI ();
    bool createComponents();

private:
    void createCells();
    void createMenu();

    static GameController *instance;
    WindowGame *windowGame = NULL;
    Game *game = NULL;
    std::vector<std::vector<EventReceiver*>> cells;
    Box *menuBox = NULL;
    Box *mine = NULL;
    Text *numFlags = NULL;
    Text *gameStatus = NULL;
    Button *playAgainButton = NULL;

public:
    void setWindowGame(WindowGame *windowGame);
    Game *getGame() {return game; }
};

#endif