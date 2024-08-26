#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(int x_param, int y_param,char colour_param) : Piece(x_param,y_param,(colour_param == 'W')? symbol_param = 'B' : symbol_param = 'b', colour_param){

}

bool Bishop::isValidMove(int oldX, int oldY, int newX, int newY, Board& board,char colour_param){
    bool valid = false;
    int odC = oldX - oldY;
    int dC = oldX + oldY;   //y = mx + c
    //std::cout << "newX + odC : " << newX + odC << '\n';
    //std::cout << "-newX + dC : "  << -newX + dC << '\n';
    if(newY == newX + odC){
        std::cout << "inside if block" << '\n';
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
        //std::cout << "inside else if" << std::endl;
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
    return valid;
}