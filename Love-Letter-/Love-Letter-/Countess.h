#pragma once
#include "Card.h"
class Countess :
    public Card
{
public:
	Countess() :Card{ "Countess",7,"If you have this card and the King of Prince in your hand, you must discard this card." } {};

	Countess(std::string name, int number, std::string description);

	Countess(const Countess& countess) { *this = countess; };

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	Card* GetInstance() { return new Countess(*this); };
};

