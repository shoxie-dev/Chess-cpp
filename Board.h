#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

class Board{
    public:
        Piece* squares[8][8]{nullptr};
        Piece* squares_t[8][8]{nullptr};

        Board();
        void printBoard();
        void movePiece(int startX, int startY, int endX, int endY);
        bool isCheck(bool isWhite) const;
        bool isCheckmate(bool isWhite) const;
        /* TODO:
            implement stalemate
            implement checkmate
            implement check
            implment place move
        */

        std::pair <int,int> choosePiece() const{
            std::pair <int, int> XY;
            std::cin >> XY.first;
            std::cin >> XY.second;
            return XY;
        }


        std::pair <int,int> newPosition() const{
            std::pair <int, int> XY;
            std::cin >> XY.first;
            std::cin >> XY.second;
            return XY;
        }
};


#endif