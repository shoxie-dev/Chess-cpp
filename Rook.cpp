#include "Rook.h"
#include "Board.h"

Rook::Rook(int x_param, int y_param, char colour_param) : Piece(x_param, y_param, (colour_param == 'W')? symbol_param = 'R' : symbol_param = 'r', colour_param){
    
}

bool Rook::isValidMove(int oldX, int oldY, int newX, int newY,Board& board, char colour_param){
    bool valid = false;
    if((newX == oldX)){
        int n = newY - oldY;
        if(n > 0){ // this is for rhs of rook
            std::cout << "inside n > 0 if block" << std::endl;
            for(int j{oldY+1}; j <= newY ; ++j){
                //oldY+1: doesnt start at the piece itself;
                //<= newY: to go a specific point and not end before the point

                if(board.getSquare(oldX,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j==newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(oldX,j) == nullptr){
                    valid = true;
                }
            }
 
        }
        
        if(n < 0){
            //std::cout << "inside n < 0 if block" << std::endl;
            for(int j{oldY-1}; j >= newY ; --j){
                //oldY-1: doesnt start at the piece itself;
                //>= newY: to go a specific point and not end before the point
                if(board.getSquare(oldX,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j==newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(oldX,j) == nullptr){
                    valid = true;
                }
            }
            
        }
          
    } 
    
    if(newY == oldY){
        int n = newX - oldX;
        std::cout << "n : " << n << '\n';
        if(n > 0){ 
            for(int i{oldX + 1}; i <= newX; ++i){
                if(board.getSquare(i,oldY)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(i==newX){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,oldY) == nullptr){
                    valid = true;
                }
            }

        }
        if(n < 0){
            for(int i{oldX-1}; i >= newX ; --i){
                if(board.getSquare(i,oldY)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(i == newX){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,oldY) == nullptr){
                    valid = true;
                }
            }

        }
    }

    return valid;
}
