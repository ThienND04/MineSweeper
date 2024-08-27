#include <Window_Start.h>

WindowStart *WindowStart::instance = NULL;

WindowStart *WindowStart::getInstance() {
    if (instance == NULL) {
        instance = new WindowStart();
        instance->setShown(true);
    }
    return instance;
}

WindowStart::WindowStart() : 
    Window(GAME_NAME.c_str(), WindowStart::WINDOW_WIDTH, WindowStart::WINDOW_HEIGHT) {
        TextureCreator::getInstance()->setRenderer(getRenderer());
        TextureCreator::getInstance()->setFont("fonts/open-sans/OpenSans-Bold.ttf", 24);
}