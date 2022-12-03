#pragma once
#include<iostream>
#include <string>
#include<random>
std::string names[8] = { "Guard","Priest","Baron","Handmaid","Prince","King","Countess","Princess" };
class Card
{private:
	std::string name;
	int number;
	std::string description;
	
public:
	Card() = default;
	Card(std::string name, int number, std::string description);
	Card(const Card& card);
	void setName(std::string name);
	std::string getName();
	void setNumber(int number);
	int getNumber();
	void setDescription(std::string description);
	std::string getDescription();
	Card createRandom();
};

