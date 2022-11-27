#pragma once
#include<iostream>
#include<string>
#include "Card.h"
class Player
{private:
	std::string name;
	Card firstCard;
	Card secondCard;
	int tokens;
public:
	Player();
	Player(std::string name, Card firstCard, Card secondCard, int tokens);
	void setName(std::string name);
	std::string getName();
	void setFirstCard(Card firstCard);
	Card getFirstCard();
	void setSecondCard(Card secondCard);
	Card getSecondCard();
	void setToken(int tokens);
	int getToken();
};

