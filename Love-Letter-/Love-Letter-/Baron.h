#pragma once
#include "Card.h"
class Baron :
    public Card
{public:
	Baron() : Card("Baron", 3, "You and another player secretly compare hands. The player with the lower value is out of the round.") {};

	Baron(std::string name, int number, std::string description);

	Baron(const Baron& baron) { *this = baron; };

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	Card* GetInstance();
};

