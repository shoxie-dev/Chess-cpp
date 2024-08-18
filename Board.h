#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

class Board{
    public:
        Piece* squares[8][8]{nullptr};
        Piece* squares_t[8][8]{nullptr};
        Board();
        void printBoard(Piece* board_i[8][8]);
};


#endif