#include <ControllerStart.h>

ControllerStart *ControllerStart::instance = NULL;

ControllerStart *ControllerStart::getInstance() {
    if (instance == NULL) {
        instance = new ControllerStart();
        instance->window = WindowStart::getInstance();
        instance->createComponents();
    }
    return instance;
}

bool ControllerStart::createComponents() {
    background = new Box(window->getRenderer());
    background->setColor(CL_PALE_GREEN);
    background->setRect({0, 0, window->getWidth(), window->getHeight()});
    window->getComponents()->push_back(background);

    btnPlay = new Button(window->getRenderer());
    btnPlay->setColor(CL_DARK_GREEN);
    btnPlay->setText("PLAY", CL_WHITE);
    btnPlay->setRect({400, 300, 200, 50});
    btnPlay->setHandleLeftClick([=](){
        Window *windowGame = new WindowGame(GameEasy::getInstance());
        Controller *newController = GameController::getInstance();
        ((GameController *) newController)->setWindowGame((WindowGame*) window);
        Minesweeper::getInstance()->setWindow(windowGame);
        Minesweeper::getInstance()->setController(newController);
    });
    window->getComponents()->push_back(btnPlay);
}

void ControllerStart::free() {
    delete background;
    delete btnPlay;

    background  = NULL;
    btnPlay = NULL;
}

void ControllerStart::updateGUI() {

}