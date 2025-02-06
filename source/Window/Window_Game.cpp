#include <Window_Game.h>

WindowGame* WindowGame::instance = NULL;

WindowGame *WindowGame::getInstance() {
    if (instance == NULL) {
        // instance = new WindowGame(new Game());
    }
    return instance;
}

WindowGame::WindowGame(Game *game) : 
    Window("Game", game->getNCol() * GRID_SIZE_DF + MENU_SIZE_WIDTH, game->getNRow() * GRID_SIZE_DF) 
{
    this->game = game;
    setGridSize(GRID_SIZE_DF);
    TextureCreator::getInstance()->setRenderer(getRenderer());
    TextureCreator::getInstance()->setFont("fonts/open-sans/OpenSans-Bold.ttf", 24);
    // std::vector<EventReceiver*> *components = getComponents();
}