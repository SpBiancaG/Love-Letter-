#include "Player.h"



Player::Player(std::string name, Card firstCard, Card secondCard, int tokens)
{
	this->name = name;
	this->firstCard = firstCard;
	this->secondCard = secondCard;
	this->tokens = tokens;
}

Player::Player(const Player& player)
{
	name = player.name;
	firstCard = player.firstCard;
	secondCard = player.secondCard;
	tokens = player.tokens;
}



void Player::SetName(std::string name)
{
	this->name = name;
}

std::string Player::GetName()
{
	return name;
}

void Player::SetFirstCard(Card firstCard)
{
	this->firstCard = firstCard;
}

Card Player::GetFirstCard()
{
	return firstCard;
}

void Player::SetSecondCard(Card secondCard)
{
	this->secondCard = secondCard;
}

Card Player::GetSecondCard()
{
	return secondCard;
}

void Player::SetToken(int tokens)
{
	this->tokens = tokens;
}

int Player::GetToken()
{
	return tokens;
}
