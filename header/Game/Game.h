#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include"enums.h"

class Game{
public:
    Game(int _nRol, int _nCol, int _numberOfMines);
    ~Game();

    void reset();
    void randomize();
    void openCell(Position pos);
    void maskCell(Position pos);
    void updateGameStatus();
    int getNumber(Position pos);
    
private:
    int nRow;
    int nCol;
    int numMines;
    int numFlag;
    std::vector<std::vector<CellType>> board;
    std::vector<std::vector<CellStatus>> boardStatus;
    GameStatus gameStatus;

// getter and setter
public: 
    int getNRow() const {
        return nRow;
    }

    void setNRow(int _nRow) {
        nRow = _nRow;
    }

    int getNCol() const {
        return nCol;
    }

    void setNCol(int _nCol) {
        nCol = _nCol;
    }

    CellType getCellType(Position pos) const {
        return board[pos.row][pos.col];
    }

    std::vector<std::vector<CellType>> getBoard() const {
        return board;
    }

    void setCellStatus(Position pos, CellStatus cellStatus) {
        boardStatus[pos.row][pos.col] = cellStatus;
    }

    CellStatus getCellStatus(Position pos) const {
        return boardStatus[pos.row][pos.col];
    }

    std::vector<std::vector<CellStatus>> getBoardStatus() const {
        return boardStatus;
    }

    GameStatus getGameStatus() const {
        return gameStatus;
    }

    void setGameStatus(GameStatus gameStatus) {
        gameStatus = gameStatus;
    }

    int getNumMines() const {
        return numMines;
    }

    int getNumFlag() const {
        return numFlag;
    }

protected:
    void setCellType(Position pos, CellType cellType) {
        board[pos.row][pos.col] = cellType;
    }
};

#endif