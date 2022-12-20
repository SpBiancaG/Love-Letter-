#pragma once

#include<string>
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

