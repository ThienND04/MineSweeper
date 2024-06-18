#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Window.h>

class Controller {
public:
    Controller();
    virtual void updateGUI ();
    virtual bool createComponents();

private:
    Window *window = NULL;
};

#endif