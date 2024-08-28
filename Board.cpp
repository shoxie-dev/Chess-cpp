#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Player.h"
#include <iostream>
#include <iomanip>

Board::Board(){
    char white = 'W';
    char black = 'B';

    // *** WHITE PIECES ***

//    squares[7][4] = new King(7,4,white);
    
//    squares[6][4] = new Queen(6,4,white); //7 3
//    squares[6][3] = new Rook(6,3,white);
//    squares[6][1] = new Rook(6,1,white);
//    squares[4][4] = new Bishop(4,4,white);
//    squares[6][6] = new Bishop(6,6,white);
//    squares[4][3] = new Knight(4,3,white);
//    squares[7][6] = new Knight(7,6,white);
   

    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(6,j,white);
    }

    // *** BLACK PIECES ***

//    squares[0][4] = new King(0,4,black);

//    squares[2][4] = new Queen(2,4,black); // 0 3
//    squares[0][5] = new Rook(0,5,black);
//    squares[0][3] = new Rook(0,3,black);
//    squares[6][5] = new Bishop(6,5,black);
//    squares[6][6] = new Bishop(6,6,black);
//    squares[0][1] = new Knight(0,1,black);
//    squares[0][6] = new Knight(0,6,black);


    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(1,j,black);
    }



    
/*  
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            squares_t[i][j] = squares[i][j]->getSymbol();//squares_t is for printing possible moves...
        }
    }
*/


}


void Board::printBoard(){
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            if(squares[i][j] == nullptr){
                
                std::cout << std::setw(2) << '.';
            }
            else {
                getSquare(i,j)->display();
            }          
        }
        std::cout << '\n';
    }
}

void Board::movePiece(int startX, int startY, int endX, int endY){
    if(getSquare(endX,endY)!=nullptr){
        if(getSquare(startX,startY)->getSymbol() != getSquare(endX,endY)->getSymbol() ){// code for when a piece is getting taken
            setEmpty(endX,endY);
        }
    }

    if(getSquare(startX,startY)->capture_enPassant == true){
        std::cout << "inside enPassant movePiece code" << '\n';
        if(getSquare(startX,startY)->getColour() == 'W'){
            setEmpty(endX+1,endY);
        }
        std::cout << "fuck you: " << getSquare(startX,startY)-> getColour() << '\n';
        if(getSquare(startX,startY)->getColour() == 'B'){
            std::cout << "inside enPassant movePiece black" << '\n';
            setEmpty(endX-1,endY);    
        }
    }


    squares[endX][endY] = squares[startX][startY];

    if(squares[startX][startY]->getisMoved() == false){
        squares[endX][endY]->setMoved();
    }


    squares[startX][startY] = nullptr; 
  
    squares[endX][endY]->setPosition(endX,endY);


}



