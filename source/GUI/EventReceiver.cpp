#include "EventReceiver.h"

EventReceiver::EventReceiver(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

bool EventReceiver::handleEvent(SDL_Event *event) {
    if (! enable) return false;
    printf ("Handling button event\n");
    // std::cout << event->type << std::endl;
    printf("1\n");
    if (event->type == SDL_MOUSEBUTTONUP) {
        printf ("Handling button click\n");
        printf("2\n");
        switch (event->button.button) {
            case (SDL_BUTTON_LEFT):
                printf("3\n");
                if(handleLeftClick != NULL) {
                    printf("4\n");
                    handleLeftClick();
                    printf("5\n");
                }
                break;
            case (SDL_BUTTON_RIGHT):
                if(handleRightClick != NULL) {
                    handleRightClick();
                }
                break;
            case (SDL_BUTTON_MIDDLE):
                if(handleMiddleClick != NULL) {
                    handleMiddleClick();
                }
                break;
        }
    }
    return true;
}

// EventReceiver::~EventReceiver() {
//     handleLeftClick.~_Func_class();
// }