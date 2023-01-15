#include "Handmaid.h"
#include<iostream>
Handmaid::Handmaid(const Handmaid& handmaid)
{
	*this = handmaid;
}
void Handmaid::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {

	player.SetIsProtected(true);
	std::cout << "Handmaid protection activated!" << std::endl;
	system("pause");
}

Card* Handmaid::GetInstance()
{
	return new Handmaid(*this);
}
