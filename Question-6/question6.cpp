#include "Move.h"
#include "Player.h"
#include "Board.h"

int main()
{
    Board board;
    Player p1("Ceco",'X');
    Player p2("Vladi",'O');

    board.SetPlayer1(p1);
    board.SetPlayer2(p2);

    //default values!
    int x,y;
    Move move;
    //Start the game
    board.Print();
    while(!board.GameOver())
    {
        cout<<"Enter x and y: ";
        cin>>x;
        move.x=x;
        cin>>y;
        move.y=y;
        board.Play(move);
        board.Print();
    }

    
}