#ifndef ENUMS_H
#define ENUMS_H

#include<iostream>

struct Position{
    int x;
    int y;

    Position(){}
    Position(int _x, int _y): x(_x), y(_y){}
};

enum GameStatus{
    GAME_RUNNING = 1, 
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_OVER = 8 | GAME_STOP
};

enum CellType{
    NONE_CELL,
    EMPTY_CELL,
    MINE_CELL,
    SCANER_CELL
};

enum CellStatus{
    CLOSED,
    OPENDED,
    MASKED
};

enum RequestType{
    NONE,
    OPEN_CELL,
    MASK_CELL,
    SCAN_CELL,
    AUTO_OPEN
};

struct Request
{
    RequestType rt;
    Position pos;

    Request(){}
};

#endif