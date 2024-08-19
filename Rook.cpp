#include "Rook.h"

Rook::Rook(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'R' : symbol_param = 'r';
}

bool Rook::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param){
    return true;
}