#include "Baron.h"

bool compareCardNumbers(Card* playerCard, Card* opponentCard) {
	if (playerCard->GetNumber() > opponentCard->GetNumber())
		return 1;
	else return 0;
}

void Baron::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	int responsePlayer;
	bool decision;

	PrintPlayers(player, players, responsePlayer, playersLen, false);
	if (responsePlayer == -1)
		return;

	if (player.GetFirstCard()->GetName() == "Baron")
		if (players[responsePlayer].GetFirstCard() != nullptr)
			decision = compareCardNumbers(player.GetSecondCard(), players[responsePlayer].GetFirstCard());
		else
			decision = compareCardNumbers(player.GetSecondCard(), players[responsePlayer].GetSecondCard());
	else
		if (players[responsePlayer].GetFirstCard() != nullptr)
			decision = compareCardNumbers(player.GetFirstCard(), players[responsePlayer].GetFirstCard());
		else
			decision = compareCardNumbers(player.GetFirstCard(), players[responsePlayer].GetSecondCard());


	if (decision) {
		players[responsePlayer].SetIsDead(true);
		nrOfPlayersInGame--;
		std::cout << "Player " << players[responsePlayer].GetName() << " was eliminated" << std::endl;
	}
	else {
		player.SetIsDead(true);
		nrOfPlayersInGame--;
		std::cout << "Player " << player.GetName() << " was eliminated" << std::endl;
	}

	system("pause");
}

Card* Baron::GetInstance()
{
	return new Baron(*this);
}
