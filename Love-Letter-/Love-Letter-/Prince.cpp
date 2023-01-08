#include "Prince.h"
#include "Game.h"

int GetPrinceCardResponse() {
	int response;
	std::cin >> response;
	if (response == 1 || response == 2)
		return response;
	else {
		std::cout << "Unknown card. Choose again!" << std::endl;
		GetPrinceCardResponse();
		return 0;
	}
	return 0;
}

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





void Prince::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	int responsePlayer;
	bool isPrincess;

	PrintPlayers(player, players, responsePlayer, playersLen, false);
	if (responsePlayer == -1)
		return;

	isPrincess = CheckIfPlayerDroppedPrincess(players[responsePlayer], nrOfPlayersInGame);
	Game* game = Game::GetInstance();

	if (!isPrincess) {
		if (players[responsePlayer].GetFirstCard() != nullptr) {
			players[responsePlayer].SetFirstCard(nullptr);
			game->PlayerDrawCard(&players[responsePlayer], playersLen);
		}
		else {
			players[responsePlayer].SetSecondCard(nullptr);
			game->PlayerDrawCard(&players[responsePlayer], playersLen);
		}
		system("pause");
	}

}