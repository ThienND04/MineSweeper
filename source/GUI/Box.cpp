#include <Box.h>

Box::Box(SDL_Renderer *renderer) :
    EventReceiver(renderer)
{
}

Box::Box(SDL_Renderer *renderer, SDL_Rect rect) :
    EventReceiver(renderer)
{
    this->rect = rect;
}

bool Box::isWithinBounds() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x >= rect.x && y >= rect.y && x < rect.x + rect.w && y <= rect.y + rect.h;
}

bool Box::isInRect(int x, int y) {
    return x >= rect.x && x <= rect.x + rect.w - 1 \
           && y >= rect.y && y <= rect.y + rect.h - 1;
}

void Box::render() {
    if (isVisible()) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);

        for (int i = 0; i < components.size(); i ++) {
            EventReceiver *cpn = components[i];
            if (cpn->isVisible()) {
                cpn->render();
            }
        }
    }
}

void Box::addComponent(EventReceiver *cpn) {
    cpn->setPos(x, y);
    components.push_back(cpn);
}