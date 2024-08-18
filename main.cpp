#include "Board.h"
#include <iostream>

int main(){
    /*
    TODO: getting movement to work
    then afterwards legal moves.
    make a pure virtual function in the base class that doesnt need to be defined there
    so it will be a boolean saying virtual bool isValidmove() = 0;
    */

    Board board;

    board.printBoard();
    return 0;
}