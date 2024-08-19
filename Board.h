#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

class Board{
    public:
        Piece* squares[8][8]{nullptr};
        Piece* squares_t[8][8]{nullptr};
        Board();
        void printBoard(Piece* squares_f[8][8]);
        bool makeMove();
        /* TODO:
            implement stalemate
            implement checkmate
            implement check
            implment place move
        */
};


#endif