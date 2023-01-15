#include "Princess.h"


Princess::Princess(const Princess& princess)
{
	*this = princess;
}

void Princess::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	player.SetIsDead(true);
	nrOfPlayersInGame--;
	std::cout << "Player " << player.GetName() << " discarded a princess. He is now dead.";
	system("pause");
	return;
}

Card* Princess::GetInstance()
{
	return new Princess(*this);
}
