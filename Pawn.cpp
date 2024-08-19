#include "Pawn.h"

Pawn::Pawn(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'P' : symbol_param = 'p';
}

bool Pawn::isValidMove(){

    return true;
}

