#include "Pawn.h"

Pawn::Pawn(char colour_param) : Piece((colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param){
    std::cout << "Pawn valid move called " << std::endl;
    return true;
}

