#ifndef CONTROLLER_START_H
#define CONTROLLER_START_H

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
#include <GameEasy.h>

class ControllerStart: public Controller {
public:
    static ControllerStart *getInstance();

    void updateGUI ();
    bool createComponents();
    void free();

private:
    static ControllerStart *instance;

    Box *background = NULL;
    Button *btnPlay = NULL;
};

#endif