#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name = "";
    symbol = '*';
}
Player::Player(string name,char symbol)
{
    this->name = name;
    this->symbol= symbol;
}
Player::Player(const Player& p)
{
    this->name=p.name;
    this->symbol=p.symbol;
}
Player::~Player()=default;

bool Player::operator==(const Player& p1)
{
    if(
    this->name == p1.name &&
    this->symbol== p1.symbol
    )
    {
    return true;
    }
}
Player Player::GetPlayer() const
{
    return *this;
}
string Player::GetPlayerName()const
{
    return this->name;
}
char Player::GetPlayerSymbol()const
{
    return this->symbol;
}
void Player::SetPlayerName(string name)
{
    this->name=name;
}
void Player::SetPlayerSymbol(char symbol)
{
    this->symbol = symbol;
}
