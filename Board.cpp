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
    
//    squares[7][3] = new Queen(7,3,white); //7 3
//    squares[7][7] = new Rook(7,7,white);
    squares[3][1] = new Rook(3,1,white);
//    squares[7][2] = new Bishop(7,2,white);
//    squares[7][5] = new Bishop(7,5,white);
//    squares[7][1] = new Knight(7,1,white);
//    squares[7][6] = new Knight(7,6,white);
   
/*
    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(6,j,white);
    }
*/
    // *** BLACK PIECES ***

    squares[0][4] = new King(0,4,black);

//    squares[0][3] = new Queen(0,3,black); // 0 3
    squares[3][3] = new Rook(3,3,black);
    squares[3][4] = new Rook(3,4,black);
//    squares[0][2] = new Bishop(0,2,black);
//    squares[0][5] = new Bishop(0,5,black);
//    squares[0][1] = new Knight(0,1,black);
//    squares[0][6] = new Knight(0,6,black);

/*
    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(1,j,black);
    }
*/

    
/*  
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            squares_t[i][j] = squares[i][j];//squares_t is for printing possible moves...
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
                squares[i][j]->display();
            }          
        }
        std::cout << '\n';
    }
}

void Board::movePiece(int startX, int startY, int endX, int endY){
    if(getSquare(endX,endY)!=nullptr){
        if(getSquare(startX,startY)->getSymbol() != getSquare(endX,endY)->getSymbol() ){// code for when a piece is getting taken
            setEmpty(endX,endY);// if a segfault occurs its this probably
        }
    }   

    squares[endX][endY] = squares[startX][startY];

    if(squares[startX][startY]->getisMoved() == false){
        squares[endX][endY]->setMoved();
    }


    squares[startX][startY] = nullptr; 
  
    squares[endX][endY]->setPosition(endX,endY);


}



