#include "Player.h"



Player::Player(std::string name, Card firstCard, Card secondCard, int tokens) :
	m_name(name),
	m_firstCard(firstCard),
	m_secondCard(secondCard),
	m_tokens(tokens)

{
	
}

Player::Player(const Player& player)
{
	*this = player;
}



void Player::SetName(std::string name)
{
	this->m_name = name;
}

std::string Player::GetName()
{
	return m_name;
}

void Player::SetFirstCard(Card firstCard)
{
	this->m_firstCard = firstCard;
}

Card Player::GetFirstCard()
{
	return m_firstCard;
}

void Player::SetSecondCard(Card secondCard)
{
	this->m_secondCard = secondCard;
}

Card Player::GetSecondCard()
{
	return m_secondCard;
}

void Player::SetToken(int tokens)
{
	this->m_tokens = tokens;
}

int Player::GetToken()
{
	return m_tokens;
}
