#ifndef TEXTURECREATOR_H
#define TEXTURECREATOR_H
#include <Texture.h>

class TextureCreator {
public:
    static TextureCreator* getInstance();
    TextureCreator(TTF_Font *font);
    TextureCreator(char* path, int fontSize);

    Texture *createTexture(std::string text, SDL_Color color, SDL_Renderer *textRenderer = NULL);

private:
    static TextureCreator* instance;
    TTF_Font *font = NULL;
    SDL_Renderer *renderer = NULL;
    TextureCreator();

public:
    bool setFont(TTF_Font *font) {this->font = font; }
    bool setFont(char* path, int fontSize);
    bool setSize(int size);
    void setRenderer(SDL_Renderer *renderer);
};

#endif