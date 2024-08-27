#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <Controller.h>
#include <GameController.h>
#include <Window.h>
#include <Window_Result.h>
#include <Window_Start.h>
#include <ControllerStart.h>
// #include <Windows.h>
#include <exception>
#include <Timer.h>

class Minesweeper{
public:
    static const int FPS = 60;
    
    Minesweeper() {}
    bool init();
    void exit();
    void start();

    static Minesweeper *getInstance();
    // can not add and remove window
    std::vector<Window *> getWindows() {return windows; }
    std::vector<Controller *> getControllers() {return controllers; }

private:
    static Minesweeper *instance;
    std::vector<Window *> windows;
    std::vector<Controller *> controllers;

    void initWindows();
    void windowsHandleEvent(SDL_Event *event);
    void clearScreens();
    void renderAll();
    void updateGUI();
};

#endif