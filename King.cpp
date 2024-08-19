#include "King.h"

King::King(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'K' : symbol_param = 'k';
}

bool King::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param){
    return true;
}