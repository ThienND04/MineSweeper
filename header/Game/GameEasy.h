#ifndef GAME_EASY_H
#define GAME_EASY_H

#include "Game.h"

class GameEasy : public Game {
public:
    GameEasy(int nRow, int nCol, int numberOfMines);
    void randomBoard();
    static GameEasy *getInstance();

    static const int N_ROW = 10;
    static const int N_COL = 10; 
    static const int N_MINES = 10; 
    
private:
    static GameEasy *instance;
};

#endif