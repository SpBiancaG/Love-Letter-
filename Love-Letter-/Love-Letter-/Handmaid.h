#pragma once
#include "Card.h"
class Handmaid :
    public Card
{
public:
	Handmaid() : Card{ "Handmaid", 4, "Until your next turn, ignore all effects from other players' cards." } {};

	Handmaid(std::string name, int number, std::string description);

	Handmaid(const Handmaid& guard);
};

