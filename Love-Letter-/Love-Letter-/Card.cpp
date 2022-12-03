#include "Card.h"


Card::Card(std::string name, int number, std::string description)
{
	this->name = name;
	this->number = number;
	this->description = description;
}

Card::Card(const Card& card)
{
	name = card.name;
	number = card.number;
	description = card.description;
}

void Card::setName(std::string name)
{
	this->name = name;
}

std::string Card::getName()
{
	return name;
}

void Card::setNumber(int number)
{
	this->number = number;
}

int Card::getNumber()
{
	return number;
}

void Card::setDescription(std::string description)
{
	this->description = description;
}

std::string Card::getDescription()
{
	return description;
}

Card Card::createRandom()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, names->size()); // define the range

	switch (distr(gen)) {
	case 0:
		return Card(names[distr(gen)], 1, "Name a non-Guard card and choose another player. If that player has that card, he or she is out of the round.");
		break;
	case 1:
		return Card(names[distr(gen)], 2, "Look at another player's hand.");
		break;
	case 2:
		return Card(names[distr(gen)], 3, "You an	d another player secretly compare hands. The player with the lower value is out of the round.");
		break;
	case 3:
		return Card(names[distr(gen)], 4, "Until your next turn, ignore all effects from other players' cards.");
		break;
	case 4:
		return Card(names[distr(gen)], 5, "Choose any player (including yourself) to discard his or her hand and draw a new card.");
		break;
	case 5:
		return Card(names[distr(gen)], 6, "Trade hands with another player of your choice.");
		break;
	case 6:
		return Card(names[distr(gen)], 7, "If you have this card and the King of Prince in your hand, you must discard this card.");
		break;
	case 7:
		return Card(names[distr(gen)], 8, "If you discard this card, you are out of the round.");
		break;
	}
	
}
