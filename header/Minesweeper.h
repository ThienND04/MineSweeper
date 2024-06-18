#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <Controller.h>
#include <GameController.h>
#include <Window.h>
#include <Window_Result.h>

class Minesweeper{
public:
    static const int FPS = 60;
    
    Minesweeper() {}
    bool init();
    void exit();
    void start();

    static Minesweeper *getInstance();

private:
    static Minesweeper *instance;
    Window* window = NULL;
    Controller *controller = NULL;

public: 
    void setWindow(Window *Window) {
        this -> window = window;
    }

    void setController(Controller *controller) {
        this -> controller = controller;
    }
};

#endif