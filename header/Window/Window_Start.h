#ifndef WINDOW_START_H
#define WINDOW_START_H

#include <Window.h>
#include <Game.h>
#include <Button.h>
#include <EventReceiver.h>
#include <TextureCreator.h>

class WindowStart : public Window {
public:
    static WindowStart *getInstance();

    WindowStart();
    ~WindowStart();

    void createComponents();

private:
    static WindowStart* instance;

    Button* easyButton = NULL;
    Button* mediumButton = NULL;
    Button* hardButton = NULL;
};

#endif