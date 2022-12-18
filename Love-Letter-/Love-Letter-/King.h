#pragma once
#include "Card.h"
class King :
    public Card
{
	King() : Card{ "King", 6, "Trade hands with another player of your choice." } {};

	King(std::string name, int number, std::string description);

	King(const King& guard);
};

