#ifndef HBOX_H
#define HBOX_H

#include "Box.h"

// You can not set the position for object in this box

class HBox : public Box {
public: 
    HBox(SDL_Renderer *renderer);
    HBox(SDL_Renderer *renderer, SDL_Rect rect);

private: 
    void addComponent(EventReceiver *cpn);
};

#endif