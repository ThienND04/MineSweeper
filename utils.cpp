#include"utils.h"

void renderGamePlay(Game& game){
    for(int i = 0; i < 30; i ++) std::cout << std::endl;

    for(int y = 0; y < game.getHeight(); y ++){
        for(int x = 0; x < game.getWidth(); x ++){
            Position pos = {x, y};
            if(game.getCellStatus(pos) == OPENDED){
                std::cout << std::setw(4) << game.getCellNumber(pos);
            }
            else if(game.getCellStatus(pos) == CLOSED){
                std::cout << std::setw(4) << - 1;
            }
            else if(game.getCellStatus(pos) == MASKED){
                std::cout << std::setw(4) << -2;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Mines remain: " << game.getNumMines() << " " 
            << "Flags remain: " << game.getNumFlag() << " "
            << "Scanner remain: " << game.getNumScanner() << std::endl;
}