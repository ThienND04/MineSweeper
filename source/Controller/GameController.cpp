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
    createCells();
    createMenu();
    return true;
}

void GameController::createCells() {
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

            btn->setTextVisible(false);
            
            btn->setHandleLeftClick([=](){
                Game *game = GameController::getInstance()->getGame();
                game->openCell({i, j});
            });

            btn->setHandleRightClick([=](){
                Game *game = GameController::getInstance()->getGame();
                game->maskCell({i, j});
            });

            btn->setHandleMiddleClick([=](){
                Game *game = GameController::getInstance()->getGame();
                game->autoOpen({i, j});
            });
            cells[i].push_back(btn);
            windowGame->getComponents()->push_back(btn);
        }
    }
}

void GameController::createMenu() {
    // menu box
    menuBox = new Box(windowGame->getRenderer());
    int h; SDL_GetWindowSize(windowGame->getWindow(), NULL, &h);
    menuBox->setRect({game->getNRow() * windowGame->getGridSize(), 0, MENU_SIZE_WIDTH, h});
    menuBox->setColor(CL_PALE_GREEN);
    windowGame->getComponents()->push_back(menuBox);

    // mine 
    mine = new Box(windowGame->getRenderer());
    mine->setRect({game->getNRow() * windowGame->getGridSize() + 25, 25, 25, 25});
    mine->setColor(CL_RED);
    windowGame->getComponents()->push_back(mine);

    numFlags = new Text(windowGame->getRenderer());
    numFlags->setText(std::to_string(game->getNumFlag()), CL_WHITE);
    numFlags->setRect({game->getNRow() * windowGame->getGridSize() + 75, 24, 25, 25});
    windowGame->getComponents()->push_back(numFlags); 

    playAgainButton = new Button(windowGame->getRenderer(), {game->getNRow() * windowGame->getGridSize() + 20, 75, 200, 25});
    playAgainButton->setColor(CL_RED);
    playAgainButton->setText("Play Again", CL_WHITE);
    playAgainButton->setHandleLeftClick([=]() {
        GameController::getInstance()->getGame()->reset();
    });
    windowGame->getComponents()->push_back(playAgainButton);
}

void GameController::setWindowGame(WindowGame *windowGame) {
    printf("set window game in controller\n");
    this->windowGame = windowGame;
    this->game = windowGame->getGame();
    createComponents();
    printf("seted window game in controller\n");
}

void GameController::updateGUI() {
    if (game -> isStarted()) {
        for (int i = 0; i < game->getNRow(); i ++) {
            for (int j = 0; j < game->getNCol(); j ++) {
                Button *btn = (Button *) cells[i][j];
                btn->setText(std::to_string(game->getNumber({i, j})).c_str(), CL_BLACK);
            }
        }
    }

    // cells
    for (int i = 0; i < game->getNRow(); i ++) {
        for (int j = 0; j < game->getNCol(); j ++) {
            Button *btn = (Button *) cells[i][j];
            if (game->getCellStatus({i, j}) == CellStatus::OPENDED) {
                if (game->getCellType({i, j}) == CellType::MINE_CELL) {
                    btn->setColor(CL_PURPLE);
                } else {
                    if ((i + j) % 2 == 0) btn->setColor(CL_DARK_BROWN);
                    else btn->setColor(CL_LIGHT_BROWN);
                    btn->setTextVisible(true);
                }
            } else if (game->getCellStatus({i, j}) == CellStatus::MASKED) {
                btn->setTextVisible(false);
                btn->setColor(CL_RED);
            } else if (game->getCellStatus({i, j}) == CellStatus::CLOSED) {
                if ((i + j) % 2 == 0) btn->setColor(CL_DARK_GREEN);
                else btn->setColor(CL_LIGHT_GREEN);
            }
        }
    }

    // menu
    numFlags->setText(std::to_string(game->getNumFlag()), CL_WHITE);
    // game->updateGameStatus();
    printf("Game status: %d\n", game->getGameStatus());
    if (game -> getGameStatus() & GameStatus::GAME_STOP) {
        printf("Game status: %d\n", game->getGameStatus());
        // Minesweeper::getInstance() -> setWindow(new WindowResult(game));
        // Minesweeper::getInstance() -> setController(new Result)
        // exit(0);
        // Minesweeper::getInstance() -> set
        if (gameStatus == NULL) {
            gameStatus = new Text(windowGame->getRenderer());
            if (game->getGameStatus() == GameStatus::GAME_WON) {
                gameStatus -> setText("WINNER", CL_RED);
            } else if (game->getGameStatus() == GameStatus::GAME_OVER) {
                gameStatus -> setText("GAME OVER", CL_RED);
            }
            gameStatus -> setRect({game->getNRow() * windowGame->getGridSize() + 20, 75, 25, 25});
            windowGame -> getComponents() -> push_back(gameStatus);
        }
        for (std::vector<EventReceiver*> row: cells) {
            for (EventReceiver *cell: row) {
                cell -> setEnable(false);
            }
        }
    }
}