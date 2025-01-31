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
                if (handleLeftClick != NULL) handleLeftClick();
                break;
            case (SDL_BUTTON_RIGHT):
                if (handleRightClick != NULL) handleRightClick();
                break;
            case (SDL_BUTTON_MIDDLE):
                if (handleMiddleClick != NULL) handleMiddleClick();
                break;
        }
    }
    return true;
}