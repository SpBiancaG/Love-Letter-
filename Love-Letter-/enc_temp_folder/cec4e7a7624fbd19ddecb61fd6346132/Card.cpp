#include "Card.h"


Card::Card(std::string nameC, int numberC, std::string descriptionC) 
	:
	m_name(nameC),
    m_number(numberC),
	m_description(descriptionC)
{
	
}


Card::Card(const Card& card){ *this = card; }




void Card::SetName(std::string name){ this->m_name = name; }

std::string Card::GetName(){ return m_name; }



void Card::SetNumber(int number){ this->m_number = number; }

int Card::GetNumber(){ return m_number; }


void Card::SetDescription(std::string description){ this->m_description = description; }

std::string Card::GetDescription(){	return m_description; }


void Card::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) 
{ std::cout << "Card base applied" << std::endl; };

Card* Card::GetInstance() { return new Card(*this); }

int Card::GetResponse(int playersLen) {
	int response;
	std::cin >> response;
	if (response >= 0 && response < playersLen)
		return response;
	else {
		std::cout << "Unknown player. Choose again!" << std::endl;
		GetResponse(playersLen);
	}
	return 0;
}

void Card::PrintPlayers(Player player, std::vector<Player> players, int& response, int playersLen, bool isPrince) {
	bool foundPlayers = false;

	std::cout << "Select a player" << std::endl;

	for (int i = 0; i < players.size(); i++) {
		if ((players[i].GetName() != player.GetName() && players[i].GetIsDead() == false && players[i].GetIsProtected() == false) || isPrince)
		{
			std::cout << i << ")" << players[i].GetName() << std::endl;
			foundPlayers = true;
		}
	}

	if (foundPlayers == true) {
		std::cout << "Selected player: ";
		response = GetResponse(playersLen);
	}
	else {
		std::cout << "No players found. All players are protected!" << std::endl;
		response = -1;
	}
}




