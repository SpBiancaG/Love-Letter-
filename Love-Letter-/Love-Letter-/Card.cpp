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



void Card::SetName(std::string name)
{
	this->name = name;
}

std::string Card::GetName()
{
	return name;
}

void Card::SetNumber(int number)
{
	this->number = number;
}

int Card::GetNumber()
{
	return number;
}

void Card::SetDescription(std::string description)
{
	this->description = description;
}

std::string Card::GetDescription()
{
	return description;
}

Card Card::CreateRandom(int number)
{
	

	
		switch (number) {
		case 1:
			return Card("Guard", 1, "Name a non-Guard card and choose another player. If that player has that card, he or she is out of the round.");
			break;
		case 2:
			return Card("Priest", 2, "Look at another player's hand.");
			break;
		case 3:
			return Card("Baron", 3, "You and another player secretly compare hands. The player with the lower value is out of the round.");
			break;
		case 4:
			return Card("Handmaid", 4, "Until your next turn, ignore all effects from other players' cards.");
			break;
		case 5:
			return Card("Prince", 5, "Choose any player (including yourself) to discard his or her hand and draw a new card.");
			break;
		case 6:
			return Card("King", 6, "Trade hands with another player of your choice.");
			break;
		case 7:
			return Card("Countess", 7, "If you have this card and the King of Prince in your hand, you must discard this card.");
			break;
		case 8:
			return Card("Princess", 8, "If you discard this card, you are out of the round.");
			break;
		}
}



