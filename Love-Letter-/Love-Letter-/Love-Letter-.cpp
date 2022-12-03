// Love-Letter-.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
int main()
{
	/*
	 int playerLen = 0;
	 cout << "Number of players: "; cin >> playerLen;

	 if (playerLen < 2 || playerLen>4) {
		 cout << "Not enough players. Try again!";
		 return 0;
	 }

	 list<Player> players;

	 for (int i = 0; i < playerLen; i++) {
		 string playerName = "";
		 Card card;
		 cout << "Player nr "<<i<<" name: "; cin >> playerName;
		 Player playerAdd(playerName, card, card, 0);
		 players.push_back(playerAdd);
	 }
	 */
	Card card;
	card = card.createRandom();
	std::cout << card.getDescription();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
