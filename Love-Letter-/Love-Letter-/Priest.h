#pragma once
#include "Card.h"
class Priest :
    public Card
{
public:
	Priest() : Card{ "Priest", 2, "Look at another player's hand." } {};

	Priest(std::string name, int number, std::string description);

	Priest(const Priest& guard);
};
