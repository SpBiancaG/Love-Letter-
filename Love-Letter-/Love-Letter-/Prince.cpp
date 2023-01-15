#include "Prince.h"
#include "Game.h"


bool CheckIfPlayerDroppedPrincess(Player& player, int& nrOfPlayersInGame) {
	if (player.GetFirstCard() != nullptr)
		if (player.GetFirstCard()->GetName() == "Princess") {
			player.SetIsDead(true);
			nrOfPlayersInGame--;
			std::cout << "Player " << player.GetName() << " card was a princess. He is now dead.";
			system("pause");
			return 1;
		}
	if (player.GetSecondCard() != nullptr)
		if (player.GetSecondCard()->GetName() == "Princess") {
			player.SetIsDead(true);
			nrOfPlayersInGame--;
			std::cout << "Player " << player.GetName() << " card was a princess. He is now dead.";
			system("pause");
			return 1;
		}
	return 0;
}





Prince::Prince(const Prince& prince)
{
	*this = prince;
}

void Prince::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	int responsePlayer;
	bool isPrincess;

	PrintPlayers(player, players, responsePlayer, playersLen, true);
	if (responsePlayer == -1)
		return;

	isPrincess = CheckIfPlayerDroppedPrincess(players[responsePlayer], nrOfPlayersInGame);
	Game* game = Game::GetInstance();

	if (!isPrincess) {
		if (players[responsePlayer].GetFirstCard() != nullptr) {
			players[responsePlayer].SetFirstCard(nullptr);
			game->PlayerDrawCard(&players[responsePlayer], playersLen,true);
		}
		else {
			players[responsePlayer].SetSecondCard(nullptr);
			game->PlayerDrawCard(&players[responsePlayer], playersLen,true);
		}
		system("pause");
	}

}

Card* Prince::GetInstance()
{
	return new Prince(*this);
}
