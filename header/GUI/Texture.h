#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
    //Initializes variables
    Texture(SDL_Renderer *renderer);
    //Deallocates memory
    ~Texture();
    //Loads image at specified path
    bool loadFromFile( std::string path );
    
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
    //Deallocates texture
    void free();
    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    //Set blending
    void setBlendMode( SDL_BlendMode blending );
    //Set alpha modulation
    void setAlpha( Uint8 alpha );
    
    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    //Gets image dimensions
    int getWidth();
    int getHeight();
    void setRenderer(SDL_Renderer *renderer) {this->renderer = renderer; }
    void setFont(TTF_Font *font) {this->font = font; }
private:
    //The actual hardware texture
    SDL_Texture* mTexture = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font = NULL;
    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif