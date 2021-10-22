#ifndef Board_h
#define Board_h
#include"Move.h"
#include"Player.h"

class Board
{
    private:
            char m_board[rowsize][colsize];
            char m_emptySpace = '*';
            bool m_bCurrentPlayer = 0;
            int m_nTurn=0;

    public:
            bool m_bIsGameOver = false;
            Player players[2];
            void SetPlayer1(Player& player1);
            void SetPlayer2(Player& player2);
            Board();
            Board(char m_board[rowsize][colsize],char m_emptySpace);
            ~Board();

            void Print();
            void Play(Move& move);
            int CheckBoardRC();
            int CheckBoardD();
            int GameOver();
};
#endif