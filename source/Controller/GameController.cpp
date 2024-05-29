#include<GameController.h>

GameController* GameController::instance = NULL;

GameController *GameController::getInstance() {
    if (instance == NULL) {
        instance = new GameController();
    } 
    return instance;
}

bool GameController::createComponents() {
    if (game == NULL) {
        printf("Game does not set in Controller!\n");
        return false;
    } 
    cells.clear();
    cells.resize(game->getNRow());
    int gridSize = windowGame->getGridSize();
    printf("Grid size: %d\n", gridSize);
    for (int i = 0; i < game->getNRow(); i ++) {
        cells[i].clear();
        for (int j = 0; j < game->getNCol(); j ++) {
            Button *btn = new Button(
                            windowGame->getRenderer(), 
                            {i * gridSize, j * gridSize, gridSize, gridSize});
            if ((i + j) % 2 == 0) btn->setColor(CL_DARK_GREEN);
            else btn->setColor(CL_LIGHT_GREEN);

            btn->setText(std::to_string(game->getNumber({i, j})).c_str(), CL_BLACK);
            btn->setTextVisible(false);
            
            btn->setEventHandleLeftClick([=](){
                Game *game = GameController::getInstance()->getGame();
                game->openCell({i, j});
            });

            btn->setEventHandleRightClick([=](){
                Game *game = GameController::getInstance()->getGame();
                game->maskCell({i, j});
            });
            cells[i].push_back(btn);
            windowGame->getComponents()->push_back(btn);
        }
    }
    return true;
}

void GameController::setWindowGame(WindowGame *windowGame) {
    printf("set window game in controller\n");
    this->windowGame = windowGame;
    this->game = windowGame->getGame();
    createComponents();
    printf("seted window game in controller\n");
}

void GameController::updateGUI() {
    for (int i = 0; i < game->getNRow(); i ++) {
        for (int j = 0; j < game->getNCol(); j ++) {
            Button *btn = (Button *) cells[i][j];
            if (game->getCellStatus({i, j}) == CellStatus::OPENDED) {
                btn->setTextVisible(true);
            } else if (game->getCellStatus({i, j}) == CellStatus::MASKED) {
                btn->setTextVisible(false);
                btn->setColor(CL_RED);
            }
        }
    }
}