#pragma once
#include "Card.h"
class Princess :
    public Card
{
public:
	Princess() : Card{ "Princess", 8, "If you discard this card, you are out of the round." } {};

	Princess(std::string name, int number, std::string description);

	Princess(const Princess& princess);

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	Card* GetInstance();
};

