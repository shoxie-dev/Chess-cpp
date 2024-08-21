#include "Rook.h"

Rook::Rook(int x_param, int y_param, char colour_param) : Piece(x_param, y_param, (colour_param == 'W')? symbol_param = 'R' : symbol_param = 'r', colour_param){
    
}

bool Rook::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param){
    return true;
}


/*
int x_param, int y_param
x_param, y_param,
*/