#include "Priest.h"

void printCards(Player player) {
	std::cout << player.GetName() << "' cards:" << std::endl;
	if (player.GetFirstCard() != nullptr) {
		std::cout << "First Card:" << player.GetFirstCard()->GetNumber() << "\t";
		std::cout << player.GetFirstCard()->GetName() << "\t";
		std::cout << player.GetFirstCard()->GetDescription() << std::endl;
	}
	if (player.GetSecondCard() != nullptr) {
		std::cout << "Second Card:" << player.GetSecondCard()->GetNumber() << "\t";
		std::cout << player.GetSecondCard()->GetName() << "\t";
		std::cout << player.GetSecondCard()->GetDescription() << std::endl;
	}
}

Priest::Priest(const Priest& priest)
{
	*this = priest;
}

void Priest::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	int responsePlayer;

	PrintPlayers(player, players, responsePlayer, playersLen, false);
	if (responsePlayer == -1)
		return;

	printCards(players[responsePlayer]);
	system("pause");
}

Card* Priest::GetInstance()
{
	return new Priest(*this);
}
