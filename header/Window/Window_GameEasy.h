#ifndef WINDOW_GAMEEASY_H
#define WINDOW_GAMEEASY_H

#include <Window_Game.h>

class WindowGameEasy : public WindowGame {
public:
    static WindowGameEasy getInstance();

private:
    static WindowGameEasy* instance;
};

#endif