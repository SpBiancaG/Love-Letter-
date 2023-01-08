#include "Player.h"




Player::Player(std::string name, Card *firstCard, Card *secondCard, uint8_t  tokens, bool isProtected, bool isDead, int cardsValue) :
	m_name(name),
	m_firstCard(firstCard),
	m_secondCard(secondCard),
	m_tokens(tokens),
	m_isProtected(isProtected),
	m_isDead(isDead),
	m_cardsValue(cardsValue)

{
	
}

Player::Player(const Player& player){	*this = player ;}

Player::~Player()
{
	//delete m_firstCard;
	//delete m_secondCard;
}

void Player::SetName(std::string name){	this->m_name = name; }
std::string Player::GetName(){	return m_name; }

void Player::SetFirstCard(Card *firstCard){	this->m_firstCard = firstCard;}
Card* Player::GetFirstCard(){	return m_firstCard;}

void Player::SetSecondCard(Card *secondCard){	this->m_secondCard = secondCard;}
Card* Player::GetSecondCard(){	return m_secondCard;}

void Player::SetToken(int tokens){	this->m_tokens = tokens;}
int Player::GetToken(){	return m_tokens;}

void Player::SetIsProtected(bool isProtected){	this->m_isProtected = isProtected;}
bool Player::GetIsProtected(){	return  m_isProtected; }

void Player::SetIsDead(bool isDead) { this->m_isDead = isDead; }
bool Player::GetIsDead() { return m_isDead; }

void Player::SetCardsValue(int cardsValue) { this->m_cardsValue = cardsValue; }
int Player::GetCardsValue() { return m_cardsValue; }