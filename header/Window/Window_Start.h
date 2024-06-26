#ifndef WINDOW_START_H
#define WINDOW_START_H

#include <Window.h>
#include <enums.h>
#include <TextureCreator.h>

class WindowStart : public Window {
public: 
    static WindowStart *getInstance();

private:
    WindowStart();
    static WindowStart *instance;
    static const int WINDOW_HEIGHT = 600;
    static const int WINDOW_WIDTH = 1000;
};


#endif
