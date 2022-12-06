#pragma once
#include<iostream>
#include <string>
#include<random>

class Card
{private:
	std::string m_name;
	uint8_t m_number;
	std::string m_description;
	
public:
	Card() = default;
	Card(std::string name, uint8_t number, std::string description);
	Card(const Card& card);
	Card& operator = (const Card& other);
	void SetName(std::string name);
	std::string GetName();
	void SetNumber(int number);
	int GetNumber();
	void SetDescription(std::string description);
	std::string GetDescription();
	Card CreateRandom(int number);
};

