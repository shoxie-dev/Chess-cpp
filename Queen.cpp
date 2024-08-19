#include "Queen.h"

Queen::Queen(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'Q' : symbol_param = 'q';
}

bool Queen::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param){
    return true;
}