#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            m_board[i][j] = m_emptySpace;
        }
    }   
}
Board::Board(char m_board[rowsize][colsize],char symbol)
{
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            m_board[i][j] = symbol;
        }
    }
}
Board::~Board()=default;
void Board::Print()
{
    for (int i = 0; i < rowsize; ++i)
    {
        cout<<"  ------------------"<<endl;
        for (int j = 0; j < colsize; ++j)
        {
        cout<<"  |  "<<m_board[i][j];
        }
        cout<<"  |  "<<endl;   
    }
        cout<<"  ------------------"<<endl;
}
void Board::SetPlayer1(Player& player1)
{
    players[0]=player1;
}

void Board::SetPlayer2(Player& player2)
{
    players[1]=player2;
}

void Board::Play(Move& move)
{
    //cout<<players[m_bCurrentPlayer].GetPlayerName()<<endl;
    if(m_board[move.x][move.y]==m_emptySpace && m_nTurn <rowsize*colsize)
    {
    m_board[move.x][move.y]=players[m_bCurrentPlayer].GetPlayerSymbol();
    m_nTurn++;
    m_bCurrentPlayer = !m_bCurrentPlayer;
    }
    else if(m_nTurn <rowsize*colsize)
    {
        cout<<"Try again!"<<endl;
    }
    else
    {
        m_bIsGameOver = true;
        cout<<"Game Over!"<<endl;
    }
}
int Board::CheckBoardRC()
{
    int countc = 1;
    char tempc;
    int countr = 1;
    char tempr;
    for (int i = 0; i < rowsize; ++i)
    {
        for (int j = 0; j < colsize-1; ++j)
        {
            tempr = m_board[i][j];
            tempc = m_board[j][i];
            if (tempr == m_board[i][j+1] && tempr != '*')
            {
                ++countr;
            }
            else
            {
                countr = 1;
            }
            if (tempc == m_board[j+1][i] && tempc != '*')
            {
                ++countc;
            }
            else
            {
                countc = 1;
            }
            
            if(countr == size || countc == size)
            {
            cout<<"[Rows and Cols] "<<players[!m_bCurrentPlayer].GetPlayerSymbol()<<"' wins the game!"<<endl;
            m_bIsGameOver = true;
            return 1;
            }
        }
    }
    return 0;
}
int Board::CheckBoardD()
{
    char tempm;
    char temps;
    int countm = 1;
    int counts = 1;

    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    for (int i = 0; i < rowsize-1; ++i)
    {
        tempm = m_board[i][i];                             //game[0][0] --> game[1][1]
        temps = m_board[i][rowsize-i-1];                   //game[0][2] --> game[1][1]
        if (tempm == m_board[i+1][i+1] && tempm != '*')
        {
            ++countm;
        }
        if (rowsize-i-2>=0 && temps == m_board[i+1][rowsize-i-2]&& temps != '*')
        {
            ++counts;
        }
        if(countm == size || counts == size)
        {
            cout<<"[Diagonals] "<<players[!m_bCurrentPlayer].GetPlayerSymbol()<<"' wins the game!"<<endl;
            m_bIsGameOver = true;
            return 1;
        }
    }
    return 0;
}
int Board::GameOver()
{
    int  nWinRows = CheckBoardRC();
    int nWinDiagonal= CheckBoardD();
    if (nWinRows!= 0 || nWinDiagonal != 0)
    {
        if(nWinRows > nWinDiagonal) 
        {
            m_bIsGameOver = true;
            return nWinRows;
        }
        else
        { 
            m_bIsGameOver = true;
            return nWinDiagonal;
        }
    }
    return 0;
}