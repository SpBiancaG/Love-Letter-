#pragma once
#include"Card.h"
class King :
    public Card
{public:
	King() : Card{ "King", 6, "Trade hands with another player of your choice." } {};

	King(std::string name, int number, std::string description);

	King(const King& king);

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	Card* GetInstance();
};

