#include <iostream>
#include <vector>

using namespace std;

constexpr const int rowsize = 3;
constexpr const int colsize = 3;
constexpr const int size = 3;

void printGame(char game[rowsize][colsize])
{
    for (int i = 0; i < rowsize; ++i)
    {
        cout<<"  -------------------"<<endl;
        for (int j = 0; j < colsize; ++j)
        {
        cout<<"  |  "<<game[i][j];
        }
        cout<<"  |  "<<endl;   
    }
        cout<<"  -------------------"<<endl;
}
int rows(char game[rowsize][colsize],int turn)
{
    int countc = 1;
    char tempc;
    int countr = 1;
    char tempr;
    for (int i = 0; i < rowsize; ++i)
    {
        for (int j = 0; j < colsize-1; ++j)
        {
            tempr = game[i][j];
            tempc = game[j][i];
            if (tempr == game[i][j+1] && tempr != '*')
            {
                ++countr;
            }
            else
            {
                countr = 1;
            }
            if (tempc == game[j+1][i] && tempc != '*')
            {
                ++countc;
            }
            else
            {
                countc = 1;
            }
            
            if(countr == size || countc == size)
            {
                return turn;
            }
        }
    }
    return 0;
}
int diagonal(char game[rowsize][colsize], int turn)
{
    char tempm;
    char temps;
    int countm = 1;
    int counts = 1;

    for (int i = 0; i < rowsize-1; ++i)
    {
        tempm = game[i][i];
        temps = game[i][rowsize-i-1];
        if (tempm == game[i+1][i+1] && tempm != '*')
        {
            ++countm;
        }
        if (rowsize-i-2>=0 && temps == game[i+1][rowsize-i-2]&& temps != '*')
        {
            ++counts;
        }
        if(countm == size || counts == size)
        {
            return turn;
        }
    }
    return 0;
}
int GameOver(char game[rowsize][colsize],int turn)
{
    int winRows = rows(game,turn);
    int winDiagonal = diagonal(game,turn);
    if (winRows != 0 || winDiagonal != 0)
    {
        if(winRows > winDiagonal)
        {
            return winRows;
        }
        else return winDiagonal;
    }
    return 0;
}

int main()
{
    vector<char> players;
    players.push_back('O');
    players.push_back('X');
    int row;
    int col;

    //Filling the game with stars
    char game[rowsize][colsize];
    for (int i = 0; i < rowsize; ++i)
    {
        for (int j = 0; j < colsize; ++j)
        {
            game[i][j] = '*';
        }
    }

    //game turns [0,9]
    int turn=0;

    //player X plays first
    bool player =true;

    printGame(game);
    while(GameOver(game,player+1) == 0 && turn <= 9)
    {         
        cin>>row>>col;
        bool canWrite = game[(int)row][(int)col]=='*';
        if(canWrite)
        {
            game[row][col]=players.at((int)player);
            turn++;
            printGame(game);

            player=!player;
        }
        else if(!canWrite)
        {
            cout<<"[Game] Bad input, try again"<<endl;
            continue;
        }
        else
        {
            cout<<"[Game] Game over, noone win"<<endl;
            system("pause");
        }
    }
    if(GameOver(game,player+1)==1)
    {
    std::cout<<"X wins!"<<endl;
    system("pause");
    }
    else
    {
    std::cout<<"O wins!"<<endl;
    system("pause");
    }
}