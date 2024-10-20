#include "cMain.h"


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Chess",wxPoint(30, 30), wxSize(1024, 768),wxCAPTION | wxCLOSE_BOX | wxSYSTEM_MENU | wxMINIMIZE_BOX)
{
    //bools
    valid_piece = false;
    valid_move = false;
    not_nullptr = false;
    correct_colour = false;

    //init player objects
    player1.setName("Player1"); 
    player1.setColour('W');

    player2.setName("Player2");
    player2.setColour('B');

    currentPlayer = &player1;
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


    for(int row{}; row < 8; ++row){
        for(int col{}; col < 8; ++col){
            int id = 1000 + (row * 8 + col); 
            buttons[row][col] = new wxButton(this, id, "", wxDefaultPosition, wxSize(64, 64));
            grid->Add(buttons[row][col], 1, wxEXPAND | wxALL);
            buttons[row][col]->Bind(wxEVT_BUTTON, &cMain::OnButtonPress, this);  
        }
    }
   
    for(int j{}; j < 8; ++j){
        buttons[1][j]->SetBitmap(pawn_black); // Set a black pawn at row 1, col 0
        buttons[6][j]->SetBitmap(pawn_white);
    }


    //white pieces
    buttons[7][4]->SetBitmap(king_white);// 7 4
    buttons[7][3]->SetBitmap(queen_white);// 7 3

    buttons[7][0]->SetBitmap(rook_white);// 7 0
    buttons[7][7]->SetBitmap(rook_white);// 7 7


    buttons[7][2]->SetBitmap(bishop_white);// 7 2
    buttons[7][5]->SetBitmap(bishop_white);// 7 5

    buttons[7][1]->SetBitmap(knight_white);// 7 1
    buttons[7][6]->SetBitmap(knight_white);// 7 6

    //black pieces
    buttons[0][4]->SetBitmap(king_black);// 0 4

    buttons[0][3]->SetBitmap(queen_black);// 0 3
 
    buttons[0][0]->SetBitmap(rook_black);// 0 0
    buttons[0][7]->SetBitmap(rook_black);// 0 7

    buttons[0][2]->SetBitmap(bishop_black);// 0 2
    buttons[0][5]->SetBitmap(bishop_black);// 0 5

    buttons[0][1]->SetBitmap(knight_black);// 0 1
    buttons[0][6]->SetBitmap(knight_black);// 0 6


    CreateStatusBar();
    SetSizer(grid);




}

cMain::~cMain()
{
    
}


void cMain::OnButtonPress(wxCommandEvent& evt) {
    wxButton* btn = dynamic_cast<wxButton*>(evt.GetEventObject());
    if (!btn) return; // Ensure the button is valid

    btn->Disable();
    if (btn) {
        int id = evt.GetId();
        int x = (id - 1000) / 8;  // Calculate row from ID
        int y = (id - 1000) % 8;  // Calculate col from ID

        
        // 1. If no piece is selected, select the piece
        if(king_check == false){
            if (selectedPiece == nullptr) { // this section of code is for if king is not in check
                not_nullptr = board.getSquare(x,y) != nullptr;
                if(not_nullptr){
                    correct_colour = board.getColourB(x,y) == currentPlayer->getColour();
                }
                valid_piece = not_nullptr && correct_colour;
                if(valid_piece){
                    selectedPiece = board.getSquare(x,y);  // Get the piece at (x, y)
                }
                if (selectedPiece != nullptr && valid_piece) {
                    // Store the coordinates of the selected piece
                    selectedX = x;
                    selectedY = y;
                    wxLogStatus("Selected piece at (%d, %d)", x, y);
                }
            }
            // 2. If a piece is already selected, move it
            else {
                // Check if the destination square is empty (or you can handle capturing here)
                if(board.getSquare(x,y) != nullptr){
                    enemy= board.getColourB(selectedX,selectedY) != board.getColourB(x,y);
                }
                
                valid_move = board.isValidMoveB(selectedX, selectedY,x,y, currentPlayer->getColour());

                if (valid_move && (board.getSquare(x,y) == nullptr || enemy)) {
                    //first deal with it visually seems to be less of a hassle for enpassant
                    wxBitmap empty_block("./assets/empty_block.png");
                    wxBitmap rook_white("./assets/wr.png");
                    wxBitmap rook_black("./assets/br.png");
                    
                    
                    bool castle_move = (selectedX == x && selectedY + 2== y) || (selectedX == x && selectedY - 2 == y);
                    if((selectedPiece->getSymbol()=='K' || selectedPiece->getSymbol()=='k') && castle_move){
                        castleGUI(x,y,empty_block,rook_white,rook_black);
                    }
                    
                    bool enpassant_legal_pos = (selectedX - 1 == x && selectedY - 1 == y) || (selectedX - 1 == x && selectedY + 1 == y) || (selectedX + 1 == x && selectedY - 1 == y ||selectedX + 1 == x && selectedY + 1 == y);
                    if(enpassant_legal_pos == true &&(selectedPiece->getSymbol() == 'P' || selectedPiece->getSymbol() == 'p')){
                        enPassantGUI(x, y, empty_block);
                    }


                    // Move the selected piece to the new square
                    board.movePiece(selectedX, selectedY, x, y);
                    board.printBoard();
                    buttons[selectedX][selectedY]->SetBitmap(empty_block);
                    wxBitmap pieceBitmap = GetPieceBitmap(board.getSquare(x, y));
                    buttons[x][y]->SetBitmap(pieceBitmap);


                    king_check = board.isCheck(currentPlayer->getColour(), attack_x, attack_y, k_x, k_y, double_check);

                    if(!king_check){
                        stale_mate = board.isStalemate(currentPlayer->getColour(),k_x,k_y);
                        if(stale_mate == true){
                            std::string message = "Game is a draw";
                            wxMessageDialog* dialog = new wxMessageDialog(nullptr, message, "Game Over", wxOK);
                            dialog->ShowModal();  // Show the dialog
                            dialog->Destroy(); 
                            wxExit();
                        }
                    }else{
                        std::string k_colour = (currentPlayer->getColour() != 'W')? "White" : "Black";
                        block_check = board.blockCheckPossible(currentPlayer->getColour(), count_check,chosen_pieces, moves ,attack_x, attack_y, k_x, k_y);
                        std::cout << std::boolalpha;
                        std::cout << block_check << '\n';
                        wxLogStatus("%s king is in check", k_colour);
                    }

                    king_checkmate = board.isCheckmate(currentPlayer->getColour());
                    if(king_check){
                        if(king_checkmate == true && !block_check){
                            std::string winner{" "};
                            std::string x_wins = " wins.";
                            if(currentPlayer->getColour() == 'W'){
                                winner = "White";
                            }else if(currentPlayer->getColour() == 'B'){
                                winner = "Black";
                            }
                            std::string message = winner + x_wins;
                            wxMessageDialog* dialog = new wxMessageDialog(nullptr, message, "Game Over", wxOK);
                            dialog->ShowModal();  // Show the dialog
                            dialog->Destroy(); 
                            wxExit();
                        }
                    }
                    if(board.getSymbolB(x,y) == 'P' && x == 0||board.getSymbolB(x,y) == 'p' && x == 7){
                        int choice;
                        pawnPromotionGUI(x,y, currentPlayer->getColour());
                    }


                    // Refresh the GUI
                    buttons[selectedX][selectedY]->Refresh();
                    buttons[selectedX][selectedY]->Update();
                    buttons[x][y]->Refresh();
                    buttons[x][y]->Update();
                    

                    // Reset selection
                    valid_piece = false;
                    valid_move = false;
                    selectedPiece = nullptr;
                    selectedX = -1;
                    selectedY = -1;
                    //switch turn
                    switchTurn(x, y);
                }else if (selectedPiece != nullptr) {
                    not_nullptr = board.getSquare(x,y) != nullptr;
                    if(not_nullptr){
                        correct_colour = board.getColourB(x,y) == currentPlayer->getColour();
                    }
                    valid_piece = not_nullptr && correct_colour;
                    if(valid_piece){
                        selectedPiece = board.getSquare(x,y);  // Get the piece at (x, y)
                    }
                
                    if (selectedPiece != nullptr && valid_piece) {
                        // Store the coordinates of the selected piece
                        selectedX = x;
                        selectedY = y;
                        wxLogStatus("Selected piece at (%d, %d)", x, y);
                    }
                }
            }
        } else{
            if(selectedPiece == nullptr){
                
                if (double_check == true) { 
                    std::cout << "King has been double checked, move to safety.\n";
                    not_nullptr = board.getSquare(k_x,k_y) != nullptr;
                    if(not_nullptr){
                        correct_colour = board.getColourB(k_x,k_y) == currentPlayer->getColour();
                    }
                    valid_piece = not_nullptr && correct_colour;
                    if(valid_piece){
                        selectedPiece = board.getSquare(k_x,k_y);  // Get the piece at (x, y)
                    }
                    if (selectedPiece != nullptr && valid_piece) {
                        // Store the coordinates of the selected piece
                        selectedX = k_x;
                        selectedY = k_y;
                        wxLogStatus("Selected piece at (%d, %d)", k_x, k_y);
                    }
                }else{
                    if (selectedPiece == nullptr) { // this section of code is for if king is not in check
                        not_nullptr = board.getSquare(x,y) != nullptr;
                        if(not_nullptr){
                            correct_colour = board.getColourB(x,y) == currentPlayer->getColour();
                        }
                        selected_pair=std::make_pair(x,y);
                        for(int i{}; i < count_check; ++i){
                            if(selected_pair == chosen_pieces[i]){
                                list_piece = true;
                                std::cout << "piece in list selected\n";
                                break;
                            }
                        }
                        valid_piece = not_nullptr && correct_colour && list_piece;
                        if(valid_piece){
                            selectedPiece = board.getSquare(x,y);  // Get the piece at (x, y)
                        }
                        if (selectedPiece != nullptr && valid_piece) {
                            // Store the coordinates of the selected piece
                            selectedX = x;
                            selectedY = y;
                            wxLogStatus("Selected piece at (%d, %d)", x, y);
                        }
                    }
                }
            } else{
                if(board.getSquare(x,y) != nullptr){
                    enemy= board.getColourB(selectedX,selectedY) != board.getColourB(x,y);
                }
                selected_move = std::make_pair(x,y);
                for(int i{}; i < count_check; ++i){
                    if(selected_pair == chosen_pieces[i] && selected_move == moves[i]){
                        std::cout << "move in list selected\n";
                        list_move = true;
                        break;
                    }
                }
                
                valid_move = list_move && board.isValidMoveB(selectedX, selectedY,x,y, currentPlayer->getColour());
                if (valid_move) { //&& (board.getSquare(x,y) == nullptr || enemy)

                    //first deal with it visually seems to be less of a hassle for enpassant
                    wxBitmap empty_block("./assets/empty_block.png");
                    wxBitmap rook_white("./assets/wr.png");
                    wxBitmap rook_black("./assets/br.png");
                    
                    
                    bool castle_move = (selectedX == x && selectedY + 2== y) || (selectedX == x && selectedY - 2 == y);
                    if((selectedPiece->getSymbol()=='K' || selectedPiece->getSymbol()=='k') && castle_move){
                        castleGUI(x,y,empty_block,rook_white,rook_black);
                    }
                    
                    bool enpassant_legal_pos = (selectedX - 1 == x && selectedY - 1 == y) || (selectedX - 1 == x && selectedY + 1 == y) || (selectedX + 1 == x && selectedY - 1 == y ||selectedX + 1 == x && selectedY + 1 == y);
                    if(enpassant_legal_pos == true &&(selectedPiece->getSymbol() == 'P' || selectedPiece->getSymbol() == 'p')){
                        enPassantGUI(x, y, empty_block);
                    }


                    // Move the selected piece to the new square
                    board.movePiece(selectedX, selectedY, x, y);
                    buttons[selectedX][selectedY]->SetBitmap(empty_block);
                    wxBitmap pieceBitmap = GetPieceBitmap(board.getSquare(x, y));
                    buttons[x][y]->SetBitmap(pieceBitmap);


                    king_check = board.isCheck(currentPlayer->getColour(), attack_x, attack_y, k_x, k_y, double_check);

                    if(!king_check){
                        stale_mate = board.isStalemate(currentPlayer->getColour(),k_x,k_y);
                        if(stale_mate == true){
                            std::string message = "Game is a draw";
                            wxMessageDialog* dialog = new wxMessageDialog(nullptr, message, "Game Over", wxOK);
                            dialog->ShowModal();  // Show the dialog
                            dialog->Destroy(); 
                            wxExit();
                        }
                    }else{
                        std::string k_colour = (currentPlayer->getColour() != 'W')? "White" : "Black";
                        block_check = board.blockCheckPossible(currentPlayer->getColour(), count_check,chosen_pieces, moves ,attack_x, attack_y, k_x, k_y);
                        std::cout << std::boolalpha;
                        std::cout << block_check << '\n';
                        wxLogStatus("%s king is in check", k_colour);
                    }

                    king_checkmate = board.isCheckmate(currentPlayer->getColour());
                    if(king_check){
                        std::cout << "inside check else block\n";
                        if(king_checkmate == true && !block_check){
                            std::string winner{" "};
                            std::string x_wins = " wins.";
                            if(currentPlayer->getColour() == 'W'){
                                winner = "White";
                            }else if(currentPlayer->getColour() == 'B'){
                                winner = "Black";
                            }
                            std::string message = winner + x_wins;
                            wxMessageDialog* dialog = new wxMessageDialog(nullptr, message, "Game Over", wxOK);
                            dialog->ShowModal();  // Show the dialog
                            dialog->Destroy(); 
                            wxExit();
                        }
                    }

                    // Refresh the GUI
                    buttons[selectedX][selectedY]->Refresh();
                    buttons[selectedX][selectedY]->Update();
                    buttons[x][y]->Refresh();
                    buttons[x][y]->Update();
                    

                    // Reset selection
                    valid_piece = false;
                    valid_move = false;
                    selectedPiece = nullptr;
                    selectedX = -1;
                    selectedY = -1;
                    //switch turn
                    switchTurn(x, y);
                }else if (selectedPiece != nullptr) {
                    not_nullptr = board.getSquare(x,y) != nullptr;
                    if(not_nullptr){
                        correct_colour = board.getColourB(x,y) == currentPlayer->getColour();
                    }
                    valid_piece = not_nullptr && correct_colour;
                    if(valid_piece){
                        selectedPiece = board.getSquare(x,y);  // Get the piece at (x, y)
                    }
                
                    if (selectedPiece != nullptr && valid_piece) {
                        // Store the coordinates of the selected piece
                        selectedX = x;
                        selectedY = y;
                        wxLogStatus("Selected piece at (%d, %d)", x, y);
                    }
                }
                
            }

        }
        
    }
    btn->Enable();
}


void cMain::PromotePawn(int x, int y, const std::string& pieceType,char colour) {
    // Replace the pawn on the board with the selected piece type
    board.pawnPromotion(x, y, pieceType,colour);

    // Update the GUI
    buttons[x][y]->SetBitmap(GetPieceBitmap(board.getSquare(x,y)));
}

void cMain::pawnPromotionGUI(int x, int y, char colour){
    PromotionDialog promotionDialog(this);

    // Show the dialog modally and wait for user selection
    if (promotionDialog.ShowModal() == wxID_OK) {
        int selectedPiece = promotionDialog.GetSelectedPiece();

        // Based on the player's choice, promote the pawn to the selected piece
        switch (selectedPiece) {
            case 1:
                // Promote to Queen
                PromotePawn(x, y, "queen",colour);
                break;
            case 2:
                // Promote to Rook
                PromotePawn(x, y, "rook",colour);
                break;
            case 3:
                // Promote to Bishop
                PromotePawn(x, y, "bishop",colour);
                break;
            case 4:
                // Promote to Knight
                PromotePawn(x, y, "knight",colour);
                break;
        }
    }
}


void cMain::castleGUI(int x, int y, wxBitmap empty, wxBitmap rook_white, wxBitmap rook_black){
    if(currentPlayer->getColour() == 'W'){
        if(selectedY > y){
            buttons[x][selectedY-1]->SetBitmap(rook_white);
            buttons[7][0]->SetBitmap(empty);
        }else if(selectedY < y){
            buttons[x][selectedY + 1]->SetBitmap(rook_white);
            buttons[7][7]->SetBitmap(empty);
        }
    } else if(currentPlayer->getColour() == 'B'){
        if(selectedY > y){
            buttons[x][selectedY-1]->SetBitmap(rook_black);
            buttons[0][0]->SetBitmap(empty);
        }else if(selectedY < y){
            buttons[x][selectedY+1]->SetBitmap(rook_black);
            buttons[0][7]->SetBitmap(empty);
        }
    }
}

void cMain::enPassantGUI(int x, int y, wxBitmap empty){
        std::cout << "inside enPassantGUI code" << '\n';
    if(board.getSquare(x+1,y)!=nullptr && board.getSquare(x+1,y)->getenPassant() == true){
        if(board.getSymbolB(selectedX, selectedY) == 'P' && board.getSymbolB(x+1,y) == 'p'){
            std::cout <<"inside enPassant movePiece White\n";
            buttons[x+1][y]->SetBitmap(empty);
            buttons[x+1][y]->Refresh();
            buttons[x+1][y]->Update();
        }
    }
    if(board.getSquare(x-1,y)!= nullptr  && board.getSquare(x-1,y)->getenPassant() == true){
        if(board.getSymbolB(selectedX, selectedY) == 'p' && board.getSymbolB(x-1,y) == 'P'){
            std::cout << "inside enPassant movePiece black" << '\n';
            buttons[x-1][y]->SetBitmap(empty);
            buttons[x-1][y]->Refresh();
            buttons[x-1][y]->Update();    
        }
    }
    
}
void cMain::UpdateBoard(int x_i, int y_i, int x_f, int y_f, char colour){

}

void cMain::switchTurn(int x, int y){
    if(currentPlayer == &player1){
        currentPlayer = &player2;
    }else{
        currentPlayer = &player1;
    }

    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(i == x && j == y){
                std::cout << '(' << x << ", " << y << ") skipped\n";
                continue;
            }
            if(board.getSquare(i, j) != nullptr){
                if(board.getSymbolB(i,j) == 'P' && board.getSquare(i,j)->getisMoved()== true && board.getSquare(i,j)->getenPassant() == true){
                    std::cout << "enpassant removed at " << i << ", " << j << '\n';
                    board.getSquare(i,j)->setenPassant(false);
                }else if(board.getSymbolB(i,j) == 'p'&& board.getSquare(i,j)->getisMoved()== true && board.getSquare(i,j)->getenPassant() == true){
                    std::cout << "enpassant removed at " << i << ", " << j << '\n';
                    board.getSquare(i,j)->setenPassant(false);
                }
            }
            
        }
    }
    
}

wxBitmap cMain::GetPieceBitmap(Piece* chesspiece){
    if(chesspiece->getSymbol() == 'P'){
        wxBitmap pawn_white("./assets/wp.png");
        return pawn_white;
    }
    if(chesspiece->getSymbol() == 'R'){
        wxBitmap rook_white("./assets/wr.png");
        return rook_white;
    }
    if(chesspiece->getSymbol() == 'B'){
        wxBitmap bishop_white("./assets/wb.png");
        return bishop_white;
    }
    if(chesspiece->getSymbol() == 'N'){
        wxBitmap knight_white("./assets/wn.png");
        return knight_white;
    }
    if(chesspiece->getSymbol() == 'Q'){
        wxBitmap queen_white("./assets/wq.png");
        return queen_white;
    }
    if(chesspiece->getSymbol() == 'K'){
        wxBitmap king_white("./assets/wk.png");
        return king_white;
    }

    if(chesspiece->getSymbol() == 'p'){
        wxBitmap pawn_black("./assets/bp.png");
        return pawn_black;
    }
    if(chesspiece->getSymbol() == 'r'){
        wxBitmap rook_black("./assets/br.png");
        return rook_black;
    }
    if(chesspiece->getSymbol() == 'b'){
        wxBitmap bishop_black("./assets/bb.png");
        return bishop_black;
    }
    if(chesspiece->getSymbol() == 'n'){
        wxBitmap knight_black("./assets/bn.png");
        return knight_black;
    }
    if(chesspiece->getSymbol() == 'q'){
        wxBitmap queen_black("./assets/bq.png");
        return queen_black;
    }
    if(chesspiece->getSymbol() == 'k'){
        wxBitmap king_black("./assets/bk.png");
        return king_black;
    }
    return wxNullBitmap;
}

