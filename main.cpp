#include "Board.h"
#include <iostream>

int main(){
    /*
    TODO: getting movement to work
    then afterwards legal moves.
    id say get pawns to work first
    make a pure virtual function in the base class that doesnt need to be defined there
    so it will be a boolean saying virtual bool isValidmove() = 0;
    */

    Board board;
    //std::cout << "Test board" << std::endl;
    //board.printBoard(board.squares_t);
    std::cout << "Game board" << std::endl;
    board.printBoard(board.squares);
    board.makeMove();
    std::cout << "making a move : " << std::endl;
    board.printBoard(board.squares);
    return 0;
}