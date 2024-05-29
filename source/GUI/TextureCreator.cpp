#include <TextureCreator.h>

TextureCreator *TextureCreator::instance = NULL;

TextureCreator *TextureCreator::getInstance() {
    if (instance == NULL) {
        instance = new TextureCreator();
    }
}

TextureCreator::TextureCreator() {};

TextureCreator::TextureCreator(TTF_Font *font) {
    setFont(font);
}

TextureCreator::TextureCreator(char* path, int fontSize) {
    setFont(path, fontSize);
}

bool TextureCreator::setFont(char* path, int fontSize) {
    bool success = false;
    try {
        font = TTF_OpenFont(path, fontSize);
        success = true;
        if(font != NULL) printf("Success load font.\n");
    } catch (std::exception e) {
        printf ("Can not load %s font. Error: %s\n", path, TTF_GetError());
    }
    return success;
}

bool TextureCreator::setSize(int size) {
    TTF_SetFontSize(font, size);
    bool success = false;
    try {
        TTF_SetFontSize(font, size);
        success = true;
    } catch (std::exception e) {
        printf ("Can not set size to current font font. Error: %s\n", TTF_GetError());
    }
    return success;
}

Texture *TextureCreator::createTexture(std::string text, SDL_Color color) {
    Texture *texture = new Texture(renderer);
    texture->setFont(font);
    if( ! texture->loadFromRenderedText(text, color)) {
        printf("Failed to render text\n");
    }
    return texture;
}

void TextureCreator::setRenderer(SDL_Renderer *renderer){
    this->renderer = renderer;
}