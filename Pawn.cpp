#include "Pawn.h"
class Piece;

Pawn::Pawn(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'P' : symbol_param = 'p';
}