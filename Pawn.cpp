#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param){
/*
    bool valid_M = false;
    if(colour_param == 'B'){
        //bool firstMoveB = true; need to add an external function or smth
        if(firstMoveB == true){
            firstMoveB = false;
            if((oldX + 1 == newX && oldY == newY) || (oldX + 2 == newX && oldY == newY)){
                valid_M = true;
            }
            
        }else{
            if(oldX + 1 == newX  && oldY == newY){
                valid_M = true;
            } else{
                std::cout << "1 move only possible not two or you didnt move straight" << std::endl;
            }
        }
    }

    if(colour_param == 'W'){
        //bool firstMoveW = true;
        if(firstMoveW == true){
            firstMoveW = false;
            if((oldX - 1 == newX  && oldY == newY) || (oldX - 2 == newX  && oldY == newY)){
                valid_M = true;
            }
            
        }else{
            if(oldX - 1 == newX  && oldY == newY){
                valid_M = true;
            } else{
                std::cout << "1 move only possible not two or you didnt move straight" << std::endl;
            }
        }

    }
    return valid_M;
*/
    return true;
}

 