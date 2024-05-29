#ifndef EVENT_RECEIVER_H
#define EVENT_RECEIVER_H

#include <SDL.h>

class EventReceiver {
public: 
    virtual bool handleEvent(SDL_Event *event) {
        return false;
    }

    virtual void render() {}
    virtual bool isInRect(int x, int y){};

private:
    char* text = "";
    SDL_Color textColor;
    bool textVisible = true;
    bool visible = true;

public:
    void setText(char* text, SDL_Color textColor) {
        this->text = text;
        this->textColor = textColor;
    }

    void setText(char* text) {
        this->text = text;
    }

    void setTextColor(SDL_Color textColor) {
        this->textColor = textColor;
    }

    void setVisible(bool visible) {
        this -> visible = visible;
    }

    bool isVisible() {
        return visible;
    }

    void setTextVisible(bool textVisible) {
        this-> textVisible = textVisible;
    }

    bool isTextVisible() {
        return textVisible;
    }
};

#endif