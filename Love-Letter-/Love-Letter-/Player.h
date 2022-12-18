#pragma once
#include<iostream>
#include<string>
#include "Card.h"
#include "Baron.h"
#include "Countess.h"
#include "Guard.h"
#include "Handmaid.h"
#include "King.h"
#include "Priest.h"
#include "Prince.h"
#include "Princess.h"
#include <vector>
class Player
{private:
	std::string m_name;
	Card *m_firstCard;
	Card *m_secondCard;
	uint8_t m_tokens=0;
public:
	Player() = default;

	Player(std::string name, Card *firstCard, Card *secondCard, uint8_t tokens);

	Player(const Player& player);

	~Player();

	void SetName(std::string name);
	std::string GetName();

	void SetFirstCard(Card *firstCard);
	Card* GetFirstCard();

	void SetSecondCard(Card *secondCard);
	Card* GetSecondCard();

	void SetToken(int tokens);
	int GetToken();

	void DrawCard(Card& card, int& cardsLen, std::vector<Card> cards);
};

