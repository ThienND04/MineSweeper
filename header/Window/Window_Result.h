#ifndef WINDOW_RESULT_H
#define WINDOW_RESULT_H

#include <Window.h>
#include <Game.h>
#include <Text.h>


class WindowResult : public Window{
public:
    WindowResult(Game *game);
    // static WindowResult *getInstance();

private:
    // static WindowResult *instance;  
};

#endif