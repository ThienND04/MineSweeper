#ifndef PLAYER_H
#define PLAYER_H

#include"enums.h"

class Player{
public:
    Player();
    ~Player();

    void getInput();

    Request getRequest() const { return request; }
    void setRequest(const Request &request_) { request = request_; }

private:
    Request request;
};


#endif