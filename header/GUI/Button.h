#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "EventReceiver.h"
#include <functional>
#include <iostream>
#include <TextureCreator.h>
#include <enums.h>

class Button : public EventReceiver {
public: 
    Button(SDL_Renderer *renderer);
    Button(SDL_Renderer *renderer, SDL_Rect rect);
    Button(SDL_Renderer *renderer, std::string text, SDL_Color textColor, SDL_Rect rect, SDL_Color color, SDL_Color hover = CL_WHITE);
    ~Button();
    // bool handleEvent(SDL_Event *event);
    virtual bool isInRect(int x, int y) override;
    virtual void render() override;
    bool isWithinBounds();
    
    void setHoverColor(SDL_Color color) {this->hoverColor = color; }
    void setRect(SDL_Rect rect) {this->rect = rect; }
    void setText(std::string text, SDL_Color textColor);

private:
    Texture* text = NULL;
    SDL_Color hoverColor {146, 145, 166, 255};
    SDL_Rect rect {0, 0, 50, 50};
    bool textVisible = true;
    
public: 
    void setTextVisible(bool textVisible) {
        this-> textVisible = textVisible;
    }

    bool isTextVisible() {
        return textVisible;
    }
};

#endif