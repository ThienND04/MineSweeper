#include "EventReceiver.h"

EventReceiver::EventReceiver(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

bool EventReceiver::handleEvent(SDL_Event *event) {
    if (! enable) return false;
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
    return true;
}