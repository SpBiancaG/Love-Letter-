#pragma once

#include<string>
#include <vector>
class Card;
class Player
{private:
	std::string m_name;
	Card *m_firstCard;
	Card *m_secondCard;
	uint8_t m_tokens=0;
	bool m_isProtected = false;
	bool m_isDead = false;
	int m_cardsValue = 0;
public:
	Player() = default;

	Player(std::string name, Card *firstCard, Card *secondCard, uint8_t tokens, bool isProtected, bool isDead, int cardsValue);

	Player(const Player& player);

	~Player()=default;

	void SetName(std::string name);
	std::string GetName();

	void SetFirstCard(Card *firstCard);
	Card* GetFirstCard();

	void SetSecondCard(Card *secondCard);
	Card* GetSecondCard();

	void SetToken(int tokens);
	int GetToken();

	void SetIsProtected(bool isProtected);
	bool GetIsProtected();

	void SetIsDead(bool isDead);
	bool GetIsDead();

	void SetCardsValue(int cardsValue);
	int GetCardsValue();

	
};

