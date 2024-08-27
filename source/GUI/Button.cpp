#include "Button.h"
#include<SDL2/SDL_image.h>

Button::Button(SDL_Renderer *renderer) :
    EventReceiver(renderer)
{
}

Button::Button(SDL_Renderer *renderer, SDL_Rect rect) :
    EventReceiver(renderer)
{
    this->rect = rect;
}

Button::~Button() {
    
}

bool Button::isWithinBounds() {
    int x_mouse, y_mouse;
    SDL_GetMouseState(&x_mouse, &y_mouse);
    return x_mouse >= x + rect.x && y_mouse >= y + rect.y && x_mouse < x + rect.x + rect.w && y_mouse <= y + rect.y + rect.h;
}

void Button::render() {
    if (isVisible()) {
        if (isWithinBounds()) {
            SDL_SetRenderDrawColor(renderer, hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a);
        } else SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect realRect = {rect.x + x, rect.y + y, rect.w, rect.h};
        SDL_RenderFillRect(renderer, &realRect);
        if (text != NULL && isTextVisible()) {
            text->render(x + rect.x + (rect.w - text->getWidth()) / 2,
                    y + rect.y + (rect.h - text->getHeight()) / 2
            );
        }
    }
}

bool Button::isInRect(int x, int y) {
    return x >= rect.x && x <= rect.x + rect.w - 1 \
           && y >= rect.y && y <= rect.y + rect.h - 1;
}

void Button::setText(std::string text, SDL_Color textColor) {
    if(this->text != NULL) this->text->free();
    this->text = TextureCreator::getInstance()->createTexture(text, textColor);
}