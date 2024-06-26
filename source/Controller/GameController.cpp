#include<GameController.h>

GameController* GameController::instance = NULL;

GameController *GameController::getInstance() {
    if (instance == NULL) {
        instance = new GameController();
    } 
    return instance;
}

// remove all component of window and recreate
bool GameController::createComponents() {
    if (game == NULL) {
        printf("Game does not set in Controller!\n");
        return false;
    } 
    free();
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

    time = new Text(windowGame->getRenderer());
    time->setRect({game->getNRow() * windowGame->getGridSize() + 75, 75, 25, 25});
    windowGame->getComponents()->push_back(time);

    playAgain = new Button(windowGame->getRenderer());
    playAgain->setText("PLAY AGAIN", CL_RED);
    playAgain->setColor(CL_LIGHT_GREEN);
    playAgain->setRect({game->getNRow() * windowGame->getGridSize() + 10, 200, 200, 75});
    playAgain->setHandleLeftClick([=](){
        printf("PLAYAGAIN\n");
        printf("Game status add: %d\n", gameStatus);
        Game *game = GameController::getInstance()->getGame();
        game->reset();
        Timer::getInstance()->start();
        createComponents();
    });
    windowGame->getComponents()->push_back(playAgain);
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
    time->setText(std::to_string(Timer::getInstance()->second()).c_str(), CL_WHITE);
    // game->updateGameStatus();
    // printf("Game status: %d\n", game->getGameStatus());
    if (game -> getGameStatus() & GameStatus::GAME_STOP) {
        printf("Game status: %d\n", game->getGameStatus());
        // Minesweeper::getInstance() -> setWindow(new WindowResult(game));
        // Minesweeper::getInstance() -> setController(new Result)
        // exit(0);
        // Minesweeper::getInstance() -> set
        Timer::getInstance()->pause();
        if (gameStatus == NULL) {
            gameStatus = new Text(windowGame->getRenderer());
            if (game->getGameStatus() == GameStatus::GAME_WON) {
                gameStatus -> setText("WINNER", CL_RED);
            } else if (game->getGameStatus() == GameStatus::GAME_OVER) {
                gameStatus -> setText("GAME OVER", CL_RED);
            }
            gameStatus -> setRect({game->getNRow() * windowGame->getGridSize() + 20, 125, 25, 25});
            windowGame -> getComponents() -> push_back(gameStatus);
        }
        for (std::vector<EventReceiver*> row: cells) {
            for (EventReceiver *cell: row) {
                cell -> setEnable(false);
            }
        }
    }
}

void GameController::free() {
    for (std::vector <EventReceiver*> vt: cells) {
        for (EventReceiver *cell: vt) {
            delete cell;
        }
        vt.clear();
    }
    cells.clear();

    // delete menuBox;
    // delete mine;
    // delete numFlags;
    printf("Game status add: %d\n", gameStatus);
    delete gameStatus;
    delete time;
    delete playAgain;

    windowGame->getComponents()->clear();

    menuBox = NULL;
    mine = NULL;
    numFlags = NULL;
    gameStatus = NULL;
    time = NULL;
    playAgain = NULL;
}