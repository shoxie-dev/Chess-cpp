#include "Game.h"
#include <iostream>

int main(){
        /*
        TODO: getting movement to work
        then afterwards legal moves.
        id say get pawns to work first
        make a pure virtual function in the base class that doesnt need to be defined there
        so it will be a boolean saying virtual bool isValidmove() = 0;
        */

    Game game("Player1","Player2");
    game.start();
    return 0;
}