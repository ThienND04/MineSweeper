#ifndef BUTTON_H
#define BUTTON_H

#include<SDL.h>
#include "EventReceiver.h"
#include <functional>
#include <iostream>
#include <TextureCreator.h>

class Button : public EventReceiver {
public: 
    Button(SDL_Renderer *renderer);
    Button(SDL_Renderer *renderer, SDL_Rect rect);
    ~Button();
    bool handleEvent(SDL_Event *event) override;
    virtual bool isInRect(int x, int y) override;
    virtual void render() override;
    
    void setColor(SDL_Color color) {this->color = color; }
    void setHoverColor(SDL_Color color) {this->hoverColor = color; }
    void setRect(SDL_Rect rect) {this->rect = rect; }
    void setEventHandleLeftClick(std::function<void()> f) {handleLeftClick = f; }
    void setEventHandleRightClick(std::function<void()> f) {handleRightClick = f; }
    void setText(std::string text, SDL_Color textColor);

private:
    SDL_Renderer* renderer;
    Texture* text = NULL;
    SDL_Color color {184, 183, 180, 255};
    SDL_Color hoverColor {146, 145, 166, 255};
    SDL_Rect rect {0, 0, 50, 50};
    std::function<void()> handleLeftClick;
    std::function<void()> handleRightClick;
    bool isWithinBounds();
};

#endif