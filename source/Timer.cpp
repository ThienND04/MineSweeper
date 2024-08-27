#include <Timer.h>

Timer *Timer::instance = NULL;

Timer *Timer::getInstance() {
    if (instance == NULL) {
        instance = new Timer();
    }
    return instance;
}

Timer::~Timer() {

}

void Timer::start() {
    timeTick = 0;
    lastTime = SDL_GetTicks();
    currentTime = lastTime;
    isRunning = true;
}

float Timer::deltaTime() {
    return 1.0 * timeTick / 1000;
}

int Timer::elapsedTicks() {
    return timeTick;
}

int Timer::second() {
    return timeTick / 1000;
}

void Timer::pause() {
    isRunning = false;
}

void Timer::resume() {
    if (! isRunning) {
        isRunning = true;
        lastTime = SDL_GetTicks();
        currentTime = lastTime;
    }
}

void Timer::update() {
    if (isRunning) {
        lastTime = currentTime;
        currentTime = SDL_GetTicks();
        timeTick += currentTime - lastTime + 1;
    }
}   