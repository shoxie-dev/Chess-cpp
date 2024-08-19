#include "Pawn.h"

Pawn::Pawn(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'P' : symbol_param = 'p';
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param){

    return true;
}

