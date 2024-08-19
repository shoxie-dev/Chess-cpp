#ifndef _GAME_
#define _GAME_
#include "Player.h"
#include "Board.h"
class Game{
    public:
        Player player1, player2;
        Board board;
        Player* currentPlayer;

        Game(std::string name1, std::string name2);
        void switchTurn();
        void start();
        bool isGameOver() const;

};

#endif