#pragma once
#include "Card.h"
class Prince :
    public Card
{
public:
	Prince() : Card{ "Prince", 5, "Choose any player (including yourself) to discard his or her hand and draw a new card." } {};

	Prince(std::string name, int number, std::string description);

	Prince(const Prince& prince);

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	Card* GetInstance();
};

