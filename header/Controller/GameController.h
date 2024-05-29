#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <Window_Game.h>
#include <Game.h>
#include <Button.h>
#include <EventReceiver.h>
#include <TextureCreator.h>
#include <vector>
#include <enums.h>
#include <string>

class GameController{
public:
    static GameController *getInstance();

    void updateGUI ();
    bool createComponents();

private:
    static GameController *instance;
    WindowGame *windowGame = NULL;
    Game *game = NULL;
    std::vector<std::vector<EventReceiver*>> cells;

public:
    void setWindowGame(WindowGame *windowGame);
    Game *getGame() {return game; }
};

#endif