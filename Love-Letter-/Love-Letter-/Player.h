#pragma once
#include<iostream>
#include<string>
#include "Card.h"
class Player
{private:
	std::string name;
	Card firstCard;
	Card secondCard;
	int tokens=0;
public:
	Player() = default;
	Player(std::string name, Card firstCard, Card secondCard, int tokens);
	Player(const Player& player);
	void SetName(std::string name);
	std::string GetName();
	void SetFirstCard(Card firstCard);
	Card GetFirstCard();
	void SetSecondCard(Card secondCard);
	Card GetSecondCard();
	void SetToken(int tokens);
	int GetToken();
};

