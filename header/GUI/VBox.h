#ifndef VBOX_H
#define VBOX_H

#include "Box.h"

// You can not set the position for object in this box

class VBox : public Box {
public: 
    VBox(SDL_Renderer *renderer);
    VBox(SDL_Renderer *renderer, SDL_Rect rect);

    void setPadding(int padding) {this->padding = padding; }

protected: 
    void addComponent(EventReceiver *cpn);
    void resetPos();

    int padding = 10;
};

#endif