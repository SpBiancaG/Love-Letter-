#include "Card.h"


Card::Card(std::string name, uint8_t number, std::string description) :
	m_name(name),
    m_number(number),
	m_description(description)
{
	
}

Card::Card(const Card& card)
{
	*this = card;
}

Card& Card::operator=(const Card& other)
{
	m_name = other.m_name;
	m_number = other.m_number;
	m_description = other.m_description;
	
	return *this;
}



void Card::SetName(std::string name)
{
	this->m_name = name;
}

std::string Card::GetName()
{
	return m_name;
}

void Card::SetNumber(int number)
{
	this->m_number = number;
}

int Card::GetNumber()
{
	return m_number;
}

void Card::SetDescription(std::string description)
{
	this->m_description = description;
}

std::string Card::GetDescription()
{
	return m_description;
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



