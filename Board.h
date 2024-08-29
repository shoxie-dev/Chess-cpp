#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

class Board{
    public:
        Piece* squares[8][8]{nullptr};
        //char squares_t[8][8]{nullptr};

        Board();
        void printBoard();
        void movePiece(int startX, int startY, int endX, int endY);
        bool isCheck(char colour) const;
        bool isCheckmate(char colour) const;
        bool castle_onceW = true;
        bool castle_onceB = true;


        std::pair <int,int> inputCoords() const{
            std::pair <int, int> XY;
            std::cin >> XY.first;
            std::cin >> XY.second;
            return XY;
        }
        
        char getSymbolB(int x,int y){// B is board
            return squares[x][y]->getSymbol();
        }
        char getColourB(int x,int y){
            return squares[x][y]->getColour();
        }
        

        Piece* getSquare(int x, int y){
            return squares[x][y];
        }

        void setNull(int x, int y){
            squares[x][y] = nullptr;
        }

        void setEmpty(int x, int y){
            delete squares[x][y];
            squares[x][y] = nullptr;
        }

        bool getCastle_onceW(){
            return castle_onceW;
        }

        void setCastle_onceW(){
            castle_onceW = false;
        }

        bool getCastle_onceB(){
            return castle_onceB;
        }

        void setCastle_onceB(){
            castle_onceB = false;
        }

        
};


#endif