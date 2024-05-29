#include "Button.h"
#include<SDL_image.h>

Button::Button(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

Button::Button(SDL_Renderer *renderer, SDL_Rect rect) {
    this->rect = rect;
    this->renderer = renderer;
}

Button::~Button() {
    
}

bool Button::handleEvent(SDL_Event *event) {
    printf ("Handling button event\n");
    std::cout << event->type << std::endl;
    if (event->type == SDL_MOUSEBUTTONUP) {
        printf ("Handling button click\n");
        switch (event->button.button) {
            case (SDL_BUTTON_LEFT):
                handleLeftClick();
                break;
            case (SDL_BUTTON_RIGHT):
                handleRightClick();
                break;
        }
    }
}

bool Button::isWithinBounds() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x >= rect.x && y >= rect.y && x < rect.x + rect.w && y <= rect.y + rect.h;
}

void Button::render() {
    if (isVisible()) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
        if (text != NULL && isTextVisible()) {
            // printf("Khong phai NULL\n");
            text->render(rect.x + (rect.w - text->getWidth()) / 2,
                    rect.y + (rect.h - text->getHeight()) / 2
            );
        }
    }
}

bool Button::isInRect(int x, int y) {
    return x >= rect.x && x <= rect.x + rect.w - 1 \
           && y >= rect.y && y <= rect.y + rect.h - 1;
}

void Button::setText(std::string text, SDL_Color textColor) {
    this->text = TextureCreator::getInstance()->createTexture(text, textColor);
}