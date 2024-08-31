#include "Queen.h"
#include "Board.h"

Queen::Queen(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'Q' : symbol_param = 'q', colour_param){
    
}

bool Queen::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    int dC = oldX + oldY;   //y = mx + c
    int odC = oldY - oldX;
    if(newY == newX + odC){//bishop code
        //std::cout << "inside newY == newX + odC" << '\n';
        int n = newY - oldY; //if positive on the rhs of the piece,lhs otherwise
        if(n > 0){
            int j{};
            for(int i{oldX + 1};i <= newX;++i){
                j = i + odC;
                if(board.getSquare(i,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j == newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,j) == nullptr){
                    valid = true;
                }

            }    
        }
        if(n < 0){
            int j{};
            for(int i{oldX - 1};i >= newX; --i){
                j = i + odC;
                
                if(board.getSquare(i,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j == newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,j) == nullptr){
                    valid = true;
                }

            }    
        }
    }

    if(newY == -newX + dC){
        //std::cout << "inside newY == -newX + dC" << std::endl;
        int n = newY - oldY;
        if(n > 0){//rhs of the piece
            std::cout << "n > 0" << '\n';
            int j{};
            for(int i{oldX - 1};i >= newX; --i){
                j = -i + dC;
                std::cout << "j : " << j << '\n';
                if(board.getSquare(i,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j == newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,j) == nullptr){
                    valid = true;
                }

            }  
 
            
        }
        if(n < 0){//lhs of the piece
            std::cout << "n < 0" << '\n';
            int j{};
            for(int i{oldX + 1};i <= newX;++i){
                j = -i + dC;
                std::cout << "j : " << j << '\n';
                if(board.getSquare(i,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    if(j == newY){// capture logic
                        if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                            valid = true;
                        }
                    }
                    break;
                }else if(board.getSquare(i,j) == nullptr){
                    valid = true;
                }

            } 

        }

    }

    if(newX == oldX){//rook code
        int n = newY - oldY;
        if(n > 0){ // this is for rhs of rook
            std::cout << "inside newX == oldX if block" << std::endl;
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
        std::cout << "inside newY == oldY block" << std::endl;
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