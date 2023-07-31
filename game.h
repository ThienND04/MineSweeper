#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include"player.h"
#include"enums.h"

class Game{
public:
    Game(int _width, int _height, int _numberOfMines);
    ~Game();

    void nextStep();
    void restart();
    bool isGameContinue();
    void openCell(Position pos);
    void maskCell(Position pos);
    void autoMaskCells(Position pos);
    bool checkWin();
    void randomBoard();
    void updateGameStatus();
    void setCellStatus(Position pos, CellStatus cellStatus);
    CellStatus getCellStatus(Position pos);
    CellType getCellType(Position pos);
    void setCellType(Position pos, CellType cellType);
    int getCellNumber(Position pos);

    const std::vector<std::vector<CellType>>& getBoard(){return board;}
    std::vector<std::vector<CellStatus>> getBoardStatus() const { return boardStatus; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    GameStatus getGameStatus() const { return gameStatus; }
    void setGameStatus(GameStatus gameStatus_) { gameStatus = gameStatus_; }

    int getNumMines() const { return numMines; }
    int getNumFlag() const { return numFlag; }
    int getNumScanner() const { return numScanner; }

private:
    int width;
    int height;
    std::vector<std::vector<CellType>> board;
    std::vector<std::vector<CellStatus>> boardStatus;
    GameStatus gameStatus;
    Player player;

    int numMines; // number of mines
    int numScanner;
    int numFlag;
};

#endif