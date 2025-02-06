#include <Window_Start.h>
#include <Window_GameEasy.h>
#include <Box.h>
#include <Minesweeper.h>
// #include <Window_GameMedium.h>
// #include <Window_GameHard.h>

WindowStart* WindowStart::instance = NULL;

WindowStart* WindowStart::getInstance() {
    if (instance == NULL) {
        printf("creating window start instance\n");
        instance = new WindowStart();
        printf("created window start instance\n");
    }
    return instance;
}

WindowStart::WindowStart() : Window("Start", 640, 480) {
    createComponents();
}

// Create components for the window
void WindowStart::createComponents() {
    getComponents()->clear();

    Box *background = new Box(getRenderer(), {0, 0, 640, 480}); 
    background->setColor(CL_GRAY);

    // Initialize buttons for difficulty selection
    easyButton = new Button(getRenderer(), "Easy", CL_RED, {220, 100, 200, 50}, CL_LIGHT_GREEN);
    mediumButton = new Button(getRenderer(), "Medium", CL_WHITE, {220, 200, 200, 50}, CL_PURPLE);
    hardButton = new Button(getRenderer(), "Hard", CL_WHITE, {220, 300, 200, 50}, CL_RED);

    easyButton->setHandleLeftClick([=]() {
        printf("setting window to easy\n");
        Minesweeper::getInstance()->setWindow(WindowGameEasy::getInstance());
        printf("set window to easy\n");
        Minesweeper::getInstance()->setController(GameController::getInstance());
        printf("setting controller to easy\n");
    });
    printf("setting handle\n");
    // mediumButton->setHandleLeftClick([]() {
    //     Minesweeper::getInstance()->setWindow(WindowGameEasy::getInstance());
    //     Minesweeper::getInstance()->setController(GameController::getInstance());
    // });

    printf("Game easy button event 1111: %d\n",  (easyButton->handleLeftClick.operator bool()));

    getComponents()->push_back(background);
    getComponents()->push_back(easyButton);
    getComponents()->push_back(mediumButton);
    getComponents()->push_back(hardButton);
}

WindowStart::~WindowStart() {
    // Cleanup if necessary
    delete easyButton;
    delete mediumButton;
    delete hardButton;
}
