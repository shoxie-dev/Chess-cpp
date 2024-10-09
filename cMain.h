#pragma once

#include "wx/wx.h"
#include "Player.h"
#include "Board.h"


class cMain : public wxFrame//start of our GUI
{
    public:
        Player player1,player2;
        Board board;
        Player* currentPlayer;
        wxButton* buttons[8][8];
        Piece* selectedPiece = nullptr;  // Holds the currently selected piece
        wxBitmap GetPieceBitmap(Piece* chesspiece);
        bool enemy;
        bool valid_piece;
        bool not_nullptr;
        bool valid_move;
        bool correct_colour;
        int selectedX = -1;  // X-coordinate of the selected piece
        int selectedY = -1;
        cMain();
        ~cMain();
        void OnButtonPress(wxCommandEvent& evt);
        void enPassantGUI(int x, int y,wxBitmap empty);
        void switchTurn(int x, int y);
        void UpdateBoard(int x_i, int y_i, int x_f, int y_f, char colour);


};  

