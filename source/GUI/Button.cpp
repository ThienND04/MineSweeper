#include "Button.h"
#include<SDL_image.h>

Button::Button(SDL_Renderer *renderer) :
    EventReceiver(renderer)
{
}

Button::Button(SDL_Renderer *renderer, SDL_Rect rect) :
    EventReceiver(renderer)
{
    this->rect = rect;
}

Button::Button(SDL_Renderer *renderer, std::string text, SDL_Color textColor, SDL_Rect rect, SDL_Color color, SDL_Color hover) : 
    EventReceiver(renderer) {
    setRect(rect);
    setText(text, textColor);
    setColor(color);
    setHoverColor(hover);
}

Button::~Button() {
    
}

// bool Button::handleEvent(SDL_Event *event) {
//     if (! isEnable()) return false;
//     // printf ("Handling button event\n");
//     std::cout << event->type << std::endl;
//     if (event->type == SDL_MOUSEBUTTONUP) {
//         // printf ("Handling button click\n");
//         switch (event->button.button) {
//             case (SDL_BUTTON_LEFT):
//                 handleLeftClick();
//                 break;
//             case (SDL_BUTTON_RIGHT):
//                 handleRightClick();
//                 break;
//             case (SDL_BUTTON_MIDDLE):
//                 handleMiddleClick();
//                 break;
//         }
//     }
//     return true;
// }

bool Button::isWithinBounds() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x >= rect.x && y >= rect.y && x < rect.x + rect.w && y <= rect.y + rect.h;
}

void Button::render() {
    if (isVisible()) {
        if (isWithinBounds()) {
            // thay cho nay = -5
            SDL_SetRenderDrawColor(renderer, hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a);
        } else SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
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
    if(this->text != NULL) this->text->free();
    this->text = TextureCreator::getInstance()->createTexture(text, textColor);
}