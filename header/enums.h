#ifndef ENUMS_H
#define ENUMS_H

#include<iostream>
#include <SDL2/SDL.h>
#include <random>
#include <ctime>
#include <algorithm>

const std::string GAME_NAME = "MINESWEEPER REAL";

struct Position{
    int row;
    int col;

    Position(){}
    Position(int _rol, int _col): row(_rol), col(_col){}
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

enum WINDOWS{
    WINDOW_START,
    WINDOW_GAME_EASY,
    WINDOW_TOTALS
};

struct Request
{
    RequestType rt;
    Position pos;

    Request(){}
};

// color
const SDL_Color CL_LIGHT_GREEN = {175, 255, 102, 255};
const SDL_Color CL_DARK_GREEN = {102, 204, 0, 255};
const SDL_Color CL_LIGHT_BROWN = {255, 204, 103, 255};
const SDL_Color CL_DARK_BROWN = {153, 76, 0, 255};
const SDL_Color CL_WHITE = {255, 250, 250, 255};
const SDL_Color CL_BLACK = {0, 0, 0, 255};
const SDL_Color CL_RED = {255, 0, 0, 255};
const SDL_Color CL_PURPLE = {128, 0, 128, 255};
const SDL_Color CL_PALE_GREEN = {152,251,152, 255};
        

// size of grid
const int GRID_SIZE_DF = 30;
const int GRID_SIZE_EASY = 35;
const int GRID_SIZE_MEDIUM = 30;
const int GRID_SIZE_HARD = 20;

// size of components
const int MENU_SIZE_WIDTH = 200;

// size of windows
const int WINDOW_RESULT_HEIGHT = 500;
const int WINDOW_RESULT_WIDTH = 500;

#endif