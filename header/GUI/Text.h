#ifndef TEXT_H
#define TEXT_H

#include <EventReceiver.h>
#include <TextureCreator.h>

class Text : public EventReceiver {
public:
    Text(SDL_Renderer *renderer);
    Text(SDL_Renderer *renderer, SDL_Rect rect);
    ~Text();
    void setText(std::string text, SDL_Color textColor);
    virtual void render() override;
    virtual bool isInRect(int x, int y){return false; }
    void setColor(SDL_Color color) {this->color = color; }
    void setRect(SDL_Rect rect) {this->rect = rect; }
    void resize(int size);

private:
    SDL_Rect rect;
    std::string strText = "";
    SDL_Color color;
    Texture *text = NULL;
};

#endif