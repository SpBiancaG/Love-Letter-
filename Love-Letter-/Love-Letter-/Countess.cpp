#include "Countess.h"

void dropCountess(Player& player, std::string name) {
	if (player.GetFirstCard() != nullptr)
		if (player.GetFirstCard()->GetName() == name)
			player.SetSecondCard(nullptr);
		else
			if (player.GetSecondCard() != nullptr)
				if (player.GetSecondCard()->GetName() == name)
					player.SetFirstCard(nullptr);
	std::cout << player.GetName() << " draw a countess but had to discard it since he had a Prince/King" << std::endl;
	system("pause");
}

void Countess::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	dropCountess(player, "King");
	dropCountess(player, "Prince");
}
