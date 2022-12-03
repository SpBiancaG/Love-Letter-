#pragma once
#include<iostream>
#include <string>
#include<random>

class Card
{private:
	std::string name;
	int number;
	std::string description;
	
public:
	Card() = default;
	Card(std::string name, int number, std::string description);
	Card(const Card& card);
	void SetName(std::string name);
	std::string GetName();
	void SetNumber(int number);
	int GetNumber();
	void SetDescription(std::string description);
	std::string GetDescription();
	Card CreateRandom(int number);
};

