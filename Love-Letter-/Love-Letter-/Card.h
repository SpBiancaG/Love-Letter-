#pragma once
#include<iostream>
#include <string>
class Card
{private:
	std::string name;
	int number;
	std::string description;
	
public:
	Card();
	Card(std::string name, int number, std::string description);
	void setName(std::string name);
	std::string getName();
	void setNumber(int number);
	int getNumber();
	void setDescription(std::string description);
	std::string getDescription();
};

