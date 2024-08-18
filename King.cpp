#include "King.h"

King::King(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'K' : symbol_param = 'k';
}

bool King::isValidMove(){
    return true;
}