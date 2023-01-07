#include "Guard.h"

int GetCardResponse() {
	int response;
	std::cin >> response;
	if (response >= 1 && response <= 7)
		return response;
	else {
		std::cout << "Unknown card. Choose again!" << std::endl;
		GetCardResponse();
		return 0;
	}
	return 0;
}


bool verifyGuardCard(std::string cardName, Player player) {
	if (player.GetFirstCard()->GetName() == cardName)
		return 1;
	else if (player.GetSecondCard()->GetName() == cardName)
		return 1;
	else return 0;
}

void Guard::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	std::cout << "Choose a card:" << std::endl;
	std::cout << "1.Priest" << std::endl;
	std::cout << "2.Baron" << std::endl;
	std::cout << "3.Handmaid" << std::endl;
	std::cout << "4.Prince" << std::endl;
	std::cout << "5.King" << std::endl;
	std::cout << "6.Countess" << std::endl;
	std::cout << "7.Princess" << std::endl;

	int responseCard, responsePlayer;
	bool isFound = false;
	std::cout << "Selected card: "; responseCard = GetCardResponse(); std::cout << std::endl;
	PrintPlayers(player, players, responsePlayer, playersLen, false);
	if (responsePlayer == -1) {
		return;
		system("pause");
	}

	switch (responseCard) {
	case 1:
		isFound = verifyGuardCard("Priest", players[responsePlayer]);
		break;
	case 2:
		isFound = verifyGuardCard("Baron", players[responsePlayer]);
		break;
	case 3:
		isFound = verifyGuardCard("Handmaid", players[responsePlayer]);
		break;
	case 4:
		isFound = verifyGuardCard("Prince", players[responsePlayer]);
		break;
	case 5:
		isFound = verifyGuardCard("King", players[responsePlayer]);
		break;
	case 6:
		isFound = verifyGuardCard("Countess", players[responsePlayer]);
		break;
	case 7:
		isFound = verifyGuardCard("Princess", players[responsePlayer]);
		break;
	}

	if (isFound) {
		std::cout << "You guessed " << players[responsePlayer].GetName() << " card" << std::endl;
		players[responsePlayer].SetIsDead(true);
		nrOfPlayersInGame--;
		system("pause");
	}
	else {
		std::cout << "You did not guessed the correct card!" << std::endl;
		system("pause");
	}
}