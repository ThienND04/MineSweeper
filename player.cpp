#include"player.h"

Player::Player(){

}

Player::~Player(){

}

void Player::getInput(){
    std::cout << "Nhap thao tac loai \"t - y x\" : ";
    int t, y, x;
    std::cin >> t >> y >> x;

    Request request;
    request.pos = {x, y};

    if(t == 1){
        request.rt = OPEN_CELL;
    }
    else if(t == 2){
        request.rt = MASK_CELL;
    }
    else if(t == 3){
        request.rt = SCAN_CELL;
    }
    else request.rt = NONE;

    setRequest(request);
}