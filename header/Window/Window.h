#ifndef WINDOW_H 
#define WINDOW_H

#include<SDL.h>
#include<stdio.h>
#include<vector>
#include<EventReceiver.h>

class Window{
public:
    Window(const char* title, int width, int height);
    ~Window();
    
    virtual void render();
    virtual void handleEvent(SDL_Event* event);
    void clearScreen();

    SDL_Window* getWindow() const {    return window; }
    SDL_Renderer* getRenderer() const { return renderer; }
    std::vector<EventReceiver*> *getComponents() { return &components; };

    int getWidth() {return width; }
    int getHeight() {return height; }

private:
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    std::vector<EventReceiver*> components;
    int windowID;
    int width;
    int height;

    bool shown;
};

#endif