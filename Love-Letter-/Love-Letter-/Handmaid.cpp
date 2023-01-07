#include "Handmaid.h"
#include<iostream>
void Handmaid::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {

	player.SetIsProtected(true);
	std::cout << "Handmaid protection activated!" << std::endl;
	system("pause");
}