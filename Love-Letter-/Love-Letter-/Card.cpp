#include "Card.h"

Card::Card()
{
	std::cout << "Default constructor";
}

Card::Card(std::string name, int number, std::string description)
{
	this->name = name;
	this->number = number;
	this->description = description;
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
