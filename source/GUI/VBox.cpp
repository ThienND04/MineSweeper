#include "VBox.h"

VBox::VBox(SDL_Renderer *renderer) : Box(renderer) {

}

VBox::VBox(SDL_Renderer *renderer, SDL_Rect rect) :
     Box(renderer, rect) {

}

void VBox::addComponent(EventReceiver *cpn) {
    Box::addComponent(cpn);
    resetPos();
}

void VBox::resetPos() {
    int totalHeight = padding * (components.size() - 1);
    int maxWidth = 0;

    for (EventReceiver *ev: components) {
        totalHeight += ev->getHeight();
        maxWidth = std::max(maxWidth, ev->getWidth());
    }

    if (totalHeight > rect.h || maxWidth > rect.w) {
        rect.h = std::max(rect.h, totalHeight);
        rect.w = std::max(rect.w, maxWidth);
        printf("Warming: The box has large objects!\n");
    }

    int initHeight = (rect.h - totalHeight) / 2;
    for (EventReceiver *ev: components) {
        SDL_Rect newRect = {
            (rect.w - ev->getWidth()) / 2,
            initHeight,
            ev->getWidth(),
            ev->getHeight()
        };
        initHeight += ev->getHeight() + padding;
        if (typeid(*ev) == typeid(Button)) {
            ((Button *) ev)->setRect(newRect);
        }
    }
}