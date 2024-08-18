#include "Rook.h"

Rook::Rook(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'R' : symbol_param = 'r';
}

bool Rook::isValidMove(){
    return true;
}