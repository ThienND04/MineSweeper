#ifndef BOX_H
#define BOX_H

#include <EventReceiver.h>
#include <vector>

class Box : public EventReceiver{
public:
    Box(SDL_Renderer *renderer);
    Box(SDL_Renderer *renderer, SDL_Rect rect);
    virtual bool isInRect(int x, int y) override;
    virtual void render() override;
    void setRect(SDL_Rect rect) {this->rect = rect; }

private:
    SDL_Rect rect {0, 0, 50, 50};
    bool isWithinBounds();
    std::vector<EventReceiver *> components;
};

#endif