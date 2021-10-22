#ifndef Player_h
#define Player_h
#include<iostream>
using namespace std;
class Player
{
    private:
            string name;
            char symbol;
            pair<int,int> move;

    public:
            Player();
            Player(string name, char symbol);
            Player(const Player& p);
            ~Player();
            
            bool operator==(const Player& p1);
            Player GetPlayer() const;
            string GetPlayerName() const;
            char GetPlayerSymbol() const;
            void SetPlayerName(string name);
            void SetPlayerSymbol(char symbol);
};
#endif