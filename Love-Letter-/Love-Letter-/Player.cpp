#include "Player.h"

Player::Player()
{
	std::cout << "Default constructor in Player";
}

Player::Player(std::string name, Card firstCard, Card secondCard, int tokens)
{
	this->name = name;
	this->firstCard = firstCard;
	this->secondCard = secondCard;
	this->tokens = tokens;
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::getName()
{
	return name;
}

void Player::setFirstCard(Card firstCard)
{
	this->firstCard = firstCard;
}

Card Player::getFirstCard()
{
	return firstCard;
}

void Player::setSecondCard(Card secondCard)
{
	this->secondCard = secondCard;
}

Card Player::getSecondCard()
{
	return secondCard;
}

void Player::setToken(int tokens)
{
	this->tokens = tokens;
}

int Player::getToken()
{
	return tokens;
}
