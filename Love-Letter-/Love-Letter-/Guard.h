#pragma once
#include "Card.h"
class Guard :
    public Card
{
public:
	Guard() : Card("Guard", 1, "Name a non-Guard card and choose another player. If that player has that card, he or she is out of the round.") {};

	Guard(std::string name, int number, std::string description);

	Guard(const Guard& guard);
};

