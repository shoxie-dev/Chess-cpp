/*
#include "cMain.h"


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Chess",wxPoint(30, 30), wxSize(1280, 1024))
{
    
    //white pieces
    wxBitmap pawn_white("./assets/wp.png");
    wxBitmap rook_white("./assets/wr.png");
    wxBitmap knight_white("./assets/wn.png");
    wxBitmap bishop_white("./assets/wb.png");
    wxBitmap king_white("./assets/wk.png");
    wxBitmap queen_white("./assets/wq.png");

    //black pieces
    wxBitmap pawn_black("./assets/bp.png");
    wxBitmap rook_black("./assets/br.png");
    wxBitmap knight_black("./assets/bn.png");
    wxBitmap bishop_black("./assets/bb.png");
    wxBitmap king_black("./assets/bk.png");
    wxBitmap queen_black("./assets/bq.png");
    
    wxGridSizer* grid = new wxGridSizer(8, 8, 0, 0);
    wxButton* buttons[8][8];

    for(int row{}; row < 8; ++row){
        for(int col{}; col < 8; ++col){
            buttons[row][col] = new wxButton(this, wxID_ANY, "", wxDefaultPosition, wxSize(60, 60));
            grid->Add(buttons[row][col], 1, wxEXPAND | wxALL);
            buttons[row][col]->Bind(wxEVT_BUTTON, &cMain::OnButtonPress, this);
        }
    }
    for(int j{}; j < 8; ++j){
        buttons[1][j]->SetBitmap(pawn_black); // Set a black pawn at row 1, col 0
        buttons[6][j]->SetBitmap(pawn_white);
    }

    buttons[7][4]->SetBitmap(king_white);
    buttons[7][3]->SetBitmap(queen_white);
    buttons[7][0]->SetBitmap(rook_white);
    buttons[7][7]->SetBitmap(rook_white);
    buttons[7][2]->SetBitmap(bishop_white);
    buttons[7][5]->SetBitmap(bishop_white);
    buttons[7][1]->SetBitmap(knight_white);
    buttons[7][6]->SetBitmap(knight_white);

    buttons[0][4]->SetBitmap(king_black);
    buttons[0][3]->SetBitmap(queen_black);
    buttons[0][0]->SetBitmap(rook_black);
    buttons[0][7]->SetBitmap(rook_black);
    buttons[0][2]->SetBitmap(bishop_black);
    buttons[0][5]->SetBitmap(bishop_black);
    buttons[0][1]->SetBitmap(knight_black);
    buttons[0][6]->SetBitmap(knight_black);

    

    SetSizer(grid);



}

cMain::~cMain()
{
    
}

void cMain::OnButtonPress(wxCommandEvent& evt){
    wxButton* btn = dynamic_cast<wxButton*>(evt.GetEventObject());
    if(btn){

    }
}
*/

