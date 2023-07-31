#include<iostream>
#include"game.h"
#include"player.h"
#include"utils.h"

// test
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 10;
const int NUMBER_OF_MINES = 10;
const int NUMBER_OF_SCANNERS = 2;

bool playAgain();

int main(int argc, char* args[]){
    Game game(BOARD_WIDTH, BOARD_HEIGHT, NUMBER_OF_MINES);

    do{
        game.restart();

        do{
            game.nextStep();
            renderGamePlay(game);
        }
        while(game.isGameContinue());

    }while(true);

    return 0;
}

bool playAgain(){
    std::cout << "Do you want to play again ? (Y/n) : ";
    char c;
    std::cin.ignore();
    std::cin >> c;

    if(c == 'y' || c == 'Y') return true;
    return false;
}