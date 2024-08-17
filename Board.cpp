#include "Board.h"
#include "Pawn.h"
#include <iostream>
#include <iomanip>

Board::Board(){
    // put pawn at (1,0)
    bool white = true;
    bool black = false;

        //int row = 1;
        //int col = 0;
        //std::cout << "Assigning Pawn at (" << row << ", " << col << ")\n";
    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(white);
    }
    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(black);
    }

    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            squares_t[i][j] = squares[i][j];//squares_t is for printing possible moves... for later
        }
    }

}


void Board::printBoard(){
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            if(squares[i][j] == nullptr){
                std::cout << std::setw(2) << '.';
            }
            else{
                squares[i][j]->display();
            }          
        }
        std::cout << '\n';
    }
}

