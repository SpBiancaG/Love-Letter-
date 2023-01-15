#pragma once

#include <string>
#include <iostream>
#include "Player.h"

class Card
{protected:
	std::string m_name;
	int m_number=0;
	std::string m_description;
	
public:
	Card() = default;

	Card(std::string name, int number, std::string description);

	Card(const Card& card);

	~Card() = default;

	void SetName(std::string name);
	std::string GetName();

	void SetNumber(int number);
	int GetNumber();

	void SetDescription(std::string description);
	std::string GetDescription();

	virtual void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);

	virtual Card* GetInstance();

	int GetResponse(int playersLen, std::vector<int> numbers);

	void PrintPlayers(Player player, std::vector<Player> players, int& response, int playersLen, bool isPrince);
};

