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
        bool king_safety;
        bool correct_colour;
        bool king_check{false};
        //variables for isCheck
        int attack_x{};
        int attack_y{};
        int k_x{}; 
        int k_y{}; 
        bool double_check{false};
        // varriables for to check if blocking a check is possible
        std::pair<int,int> chosen_pieces[128];
        std::pair<int,int> moves[128];
        std::pair<int,int> selected_pair;
        std::pair<int,int> selected_move;
        int count_check{};
        bool block_check{false};
        bool list_piece{false};
        bool list_move{false};
        //
        bool stale_mate;
        bool king_checkmate;
        int selectedX = -1;  // X-coordinate of the selected piece
        int selectedY = -1;
        cMain();
        ~cMain();
        void OnButtonPress(wxCommandEvent& evt);
        void pawnPromotionGUI(int x, int y, char colour);
        void enPassantGUI(int x, int y,wxBitmap empty);
        void PromotePawn(int x, int y, const std::string& pieceType,char colour);
        void castleGUI(int x, int y, wxBitmap empty, wxBitmap rook_white, wxBitmap rook_black);
        void switchTurn(int x, int y);
        void UpdateBoard(int x_i, int y_i, int x_f, int y_f, char colour);


};  

class PromotionDialog : public wxDialog {
public:
    PromotionDialog(wxWindow* parent)
        : wxDialog(parent, wxID_ANY, "Pawn Promotion", wxDefaultPosition, wxSize(250, 450),
         wxCAPTION | wxSTAY_ON_TOP | wxSYSTEM_MENU) {

        // Create buttons for each promotion option
        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

        wxButton* queenBtn = new wxButton(this, wxID_HIGHEST + 1, "Queen");
        wxButton* rookBtn = new wxButton(this, wxID_HIGHEST + 2, "Rook");
        wxButton* bishopBtn = new wxButton(this, wxID_HIGHEST + 3, "Bishop");
        wxButton* knightBtn = new wxButton(this, wxID_HIGHEST + 4, "Knight");

        // Add buttons to the sizer
        vbox->Add(queenBtn, 1, wxEXPAND | wxALL, 10);
        vbox->Add(rookBtn, 1, wxEXPAND | wxALL, 10);
        vbox->Add(bishopBtn, 1, wxEXPAND | wxALL, 10);
        vbox->Add(knightBtn, 1, wxEXPAND | wxALL, 10);
    
        // Set the sizer
        this->SetSizer(vbox);
        this->Layout();

        // Bind the button events to the appropriate handler
        Bind(wxEVT_BUTTON, &PromotionDialog::OnSelect, this);
    }

    int GetSelectedPiece() const { return selectedPiece; }

private:
    int selectedPiece;

    void OnSelect(wxCommandEvent& event) {
        // Determine which button was clicked and set the selected piece
        int id = event.GetId();
        if (id == wxID_HIGHEST + 1) selectedPiece = 1;  // Queen
        else if (id == wxID_HIGHEST + 2) selectedPiece = 2;  // Rook
        else if (id == wxID_HIGHEST + 3) selectedPiece = 3;  // Bishop
        else if (id == wxID_HIGHEST + 4) selectedPiece = 4;  // Knight

        // Close the dialog
        EndModal(wxID_OK);
    }
};

