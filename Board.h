#ifndef _BOARD_
#define _BOARD_

#include "Piece.h"

class Board{
    private:
        Piece* squares[8][8]{nullptr};
        bool castle_onceW = true;
        bool castle_onceB = true;     

    public:
        Board();
        void printBoard();
        void movePiece(int x_i, int y_i, int x_f, int y_f);
        void pawnPromotion(char colour);
        bool isCheck(char colour, int& k_x, int& k_y);
        bool isCheckmate(char colour);
        bool isStalemate(char colour, int k_x, int k_y);
        bool isKingSafeB(int x_i, int y_i, int x_f, int y_f);
        bool blockCheckPossible(char colour,int* pieces_avail[][2]);
        void castleRook(int x_i, int y_i, int x_f, int y_f);
        void takeEnPassant(int x_i, int y_i, int x_f, int y_f);


        std::pair <int,int> inputCoords() const{
            std::pair <int, int> XY;
            std::cin >> XY.first;
            std::cin >> XY.second;
            return XY;
        }
        
        char getSymbolB(int x,int y){
            return squares[x][y]->getSymbol();
        }
        char getColourB(int x,int y){
            return squares[x][y]->getColour();
        }

        void setSquare(int x_f,int y_f,int x_i,int y_i){
            squares[x_f][y_f] = squares[x_i][y_i];
        }

        void initPiece( int x, int y, Piece* init_piece){
            squares[x][y] = init_piece;
        }

        Piece* getSquare(int x, int y){
            return squares[x][y];
        }

        void setNull(int x, int y){
            squares[x][y] = nullptr;
        }

        void setTaken(int x, int y){
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