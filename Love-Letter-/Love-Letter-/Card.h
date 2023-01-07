#pragma once

#include <string>
#include "Player.h"

class Card
{protected:
	std::string m_name;
	uint8_t m_number;
	std::string m_description;
	
public:
	Card() = default;

	Card(std::string name, uint8_t number, std::string description);

	Card(const Card& card);

	void SetName(std::string name);
	std::string GetName();

	void SetNumber(uint8_t number);
	int GetNumber();

	void SetDescription(std::string description);
	std::string GetDescription();

	virtual void action(Player& player, std::vector<Player>& players);
	virtual Card* GetInstance();
	
};

