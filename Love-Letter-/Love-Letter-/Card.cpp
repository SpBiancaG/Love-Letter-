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




void Card::SetName(std::string name)
{
	this->m_name = name;
}

std::string Card::GetName()
{
	return m_name;
}



void Card::SetNumber(uint8_t number)
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
Card& Card::operator=(const Card& other)
{
	m_name = other.m_name;
	m_number = other.m_number;
	m_description = other.m_description;

	return *this;
}

void Card::action(Player player) {};





