#include "Baron.h"
#include "Countess.h"
#include "Guard.h"
#include "Handmaid.h"
#include "King.h"
#include "Priest.h"
#include "Prince.h"
#include "Princess.h"
#include<iostream>

void printPlayers(Player player, std::vector<Player> players, int& response) {
	std::cout << "Select a player" << std::endl;
	for (int i = 0; i < players.size(); i++) {
		if (players[i].GetName() != player.GetName())
		{
			std::cout << i << ")" << players[i].GetName() << std::endl;
		}
	}
	std::cout << "Selected player: "; std::cin >> response;
}

void Baron::action(Player& player, std::vector<Player>& players) {
	int responsePlayer;

	printPlayers(player, players, responsePlayer);

	int sumaPlayer = player.GetFirstCard()->GetNumber() + player.GetSecondCard()->GetNumber();
	int sumaPlayerConcurent = players[responsePlayer].GetFirstCard()->GetNumber() + players[responsePlayer].GetSecondCard()->GetNumber();

	if (sumaPlayer > sumaPlayerConcurent)
		std::cout << player.GetName() << " is out" << std::endl;
	else
		std::cout << players[responsePlayer].GetName() << " is out" << std::endl;
}

void Countess::action(Player& player, std::vector<Player>& players) {

	std::cout << "Countess action" << std::endl;
}

bool verifyGuardCard(std::string cardName, Player player) {
	if (player.GetFirstCard()->GetName() == cardName)
		return 1;
	else if (player.GetSecondCard()->GetName() == cardName)
		return 1;
	else return 0;
}

void Guard::action(Player& player, std::vector<Player>& players) {
	std::cout << "Choose a card:" << std::endl;
	std::cout << "1.Priest" << std::endl;
	std::cout << "2.Baron" << std::endl;
	std::cout << "3.Handmaid" << std::endl;
	std::cout << "4.Prince" << std::endl;
	std::cout << "5.King" << std::endl;
	std::cout << "6.Countess" << std::endl;
	std::cout << "7.Princess" << std::endl;

	int responseCard, responsePlayer, isFound;
	std::cout << "Selected card: "; std::cin >> responseCard; std::cout << std::endl;
	printPlayers(player, players, responsePlayer);

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

	if (isFound)
		std::cout << "A fost gasita" << std::endl;
	else
		std::cout << "Nu a fost gasita" << std::endl;
}

void Handmaid::action(Player& player, std::vector<Player>& players) {

	std::cout << "Handmaid action" << std::endl;
	player.SetIsProtected(true);
}

template <class Card>
void SwapCards(Card* card1, Card* card2) {
	Card tmp(std::move(*card1));
	*card1 = std::move(*card2);
	*card2 = std::move(tmp);
}

void King::action(Player& player, std::vector<Player>& players) {
	int responsePlayer;

	printPlayers(player, players, responsePlayer);

	SwapCards(player.GetFirstCard(), players[responsePlayer].GetFirstCard());
	SwapCards(player.GetSecondCard(), players[responsePlayer].GetSecondCard());

	std::cout << "King action" << std::endl;
}

void printCards(Player player) {
	std::cout << player.GetName() << "' cards:" << std::endl;
	std::cout << "First Card:" << player.GetFirstCard()->GetNumber() << "\t";
	std::cout << player.GetFirstCard()->GetName() << "\t";
	std::cout << player.GetFirstCard()->GetDescription() << std::endl;
	std::cout << "Second Card:" << player.GetSecondCard()->GetNumber() << "\t";
	std::cout << player.GetSecondCard()->GetName() << "\t";
	std::cout << player.GetSecondCard()->GetDescription() << std::endl;
}

void Priest::action(Player& player, std::vector<Player>& players) {
	int responsePlayer;

	printPlayers(player, players, responsePlayer);

	printCards(players[responsePlayer]);
}

void Prince::action(Player& player, std::vector<Player>& players) {
	int responseCard, responsePlayer;

	std::cout << "Select a player" << std::endl;

	for (int i = 0; i < players.size(); i++)
		std::cout << i << ")" << players[i].GetName() << std::endl;

	std::cout << "Selected player: "; std::cin >> responsePlayer;

	printCards(players[responsePlayer]);

	std::cout << "Selected card: "; std::cin >> responseCard;

	if (responseCard == 1)
		players[responseCard].SetFirstCard(new Card());
	else if (responseCard == 2)
		players[responseCard].SetSecondCard(new Card());
	else
		std::cout << "Wrongs card choosen" << std::endl;
}

void Princess::action(Player& player, std::vector<Player>& players) {

	std::cout << "Princess action" << std::endl;
}