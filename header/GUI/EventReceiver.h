#ifndef EVENT_RECEIVER_H
#define EVENT_RECEIVER_H

#include <SDL.h>
#include <iostream>
#include <functional>

class EventReceiver {
public: 
    EventReceiver(SDL_Renderer *renderer);
    bool handleEvent(SDL_Event *event);
    virtual void render() {}
    virtual bool isInRect(int x, int y){};
    void setHandleLeftClick(std::function<void()> f) {handleLeftClick = f; }
    void setHandleRightClick(std::function<void()> f) {handleRightClick = f; }
    void setHandleMiddleClick(std::function<void()> f) {handleMiddleClick = f; }

public:
    SDL_Renderer* renderer;
    bool visible = true;
    bool enable = true;
    std::function<void()> handleLeftClick = NULL;
    std::function<void()> handleRightClick = NULL;
    std::function<void()> handleMiddleClick = NULL;
    SDL_Color color;

public:
    void setVisible(bool visible) {
        this -> visible = visible;
    }

    bool isVisible() {
        return visible;
    }

    bool isEnable() {
        return enable;
    }

    void setEnable(bool enable) {
        this -> enable = enable;
    }

    void setColor(SDL_Color color) {this->color = color; }
};

#endif