#include "Player.h"
#include "Card.h"



Player::Player(std::string nameC, Card *firstCardC, Card *secondCardC, uint8_t  tokensC, bool isProtectedC) :
	m_name(nameC),
	m_firstCard(firstCardC),
	m_secondCard(secondCardC),
	m_tokens(tokensC),
	m_isProtected(isProtectedC)

{
	
}

Player::Player(const Player& player)
{
	*this = player;
}

Player::~Player()
{
	//delete m_firstCard;
	//delete m_secondCard;
}



void Player::SetName(std::string name)
{
	this->m_name = name;
}

std::string Player::GetName()
{
	return m_name;
}

void Player::SetFirstCard(Card *firstCard)
{
	this->m_firstCard = firstCard;
}

Card* Player::GetFirstCard()
{
	return m_firstCard;
}

void Player::SetSecondCard(Card *secondCard)
{
	this->m_secondCard = secondCard;
}

Card* Player::GetSecondCard()
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

void Player::SetIsProtected(bool isProtected)
{
	this->m_isProtected = isProtected;
}

bool Player::GetIsProtected()
{
	return  m_isProtected;
}
