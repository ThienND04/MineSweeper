#include<Text.h>

Text::Text(SDL_Renderer *renderer) :
    EventReceiver(renderer)
{
}

Text::Text(SDL_Renderer *renderer, SDL_Rect rect) :
    EventReceiver(renderer)
{
    this->rect = rect;
}

Text::~Text() {
    
}


void Text::render() {
    if (text != NULL && isVisible()) {
        text->render(rect.x, rect.y);
    }
}

void Text::setText(std::string text, SDL_Color textColor) {
    if (this->text != NULL) {
        this->text->free();
    }
    this->strText = text;
    this->color = textColor;
    this->text = TextureCreator::getInstance()->createTexture(text, textColor);
}

void Text::resize(int size) {
    if (this->text != NULL) {
        this->text->free();
    }
    TextureCreator::getInstance()->setSize(size);
    this->text = TextureCreator::getInstance()->createTexture(strText, color);
}