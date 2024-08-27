#include <GameEasy.h>

GameEasy* GameEasy::instance = NULL;

GameEasy::GameEasy(int _nRow, int _nCol, int _numberOfMines) : Game(_nRow, _nCol, _numberOfMines) {
    
}

GameEasy *GameEasy::getInstance() {
    if (instance == NULL) {
        printf("create instance\n");
        instance = new GameEasy(N_ROW, N_COL, N_MINES);
    }
    // int r = instance->getNRow(), c = instance->getNCol();
    // // printf("Game size: %d %d\n", r, c);
    // printf("Instance add: %p\n", instance);
    return instance;
}

void GameEasy::randomBoard() {
    
}

