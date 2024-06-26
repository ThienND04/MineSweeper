#ifndef UTILS_H
#define UTILS_H

#include <SDL.h>

class Timer {
public:
    static Timer *getInstance();
    ~Timer();
    void start();
    float deltaTime();
    int elapsedTicks();
    int second();
    void pause();
    void resume();
    void update();

private:
    static Timer *instance;
    Timer() {
        start();
    }

    int timeTick = 0;
    int currentTime = 0;
    int lastTime = 0;
    bool isRunning = true;
};

#endif