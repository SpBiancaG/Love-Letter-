#include "Game.h"

void Game::NextPlayer()
{
	
		this->selectedPlayerToPlay++;
}

int Game::GetRandomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, availableCardsLen); // define the range
	int randomNr = distr(gen);
	for (int i = randomNr; i < availableCardsLen; ++i)
		availableCards[i] = availableCards[i + 1];
	availableCards[availableCardsLen] = 0;
	availableCardsLen--;
	return randomNr;
}

void Game::SetStartingPlayers()
{
	int playerLen = 0;
	std::cout << "Number of players: "; std::cin >> playerLen;

	if (playerLen < 2 || playerLen>4) {
		std::cout << "Not enough players. Try again!";
		return;
	}
	GetBeginningCards(playerLen);
	for (int i = 0; i < playerLen; i++) {
		std::string playerName = "";
		Card card;
		std::cout << "Player nr " << i << " name: "; std::cin >> playerName;
		Player playerAdd(playerName, card.CreateRandom(GetRandomNumber()), card, 0);
		std::cout << playerAdd.getSecondCard().GetName();
		

		this->players.push_back(playerAdd);
	}
}



void Game::PrintStartingGame()
{
	std::cout << players[selectedPlayerToPlay].getName() << "' turn" << std::endl << std::endl;
	std::cout << "First Card:" << players[selectedPlayerToPlay].getFirstCard().GetNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].getFirstCard().GetName() << std::endl;
	std::cout << "Second Card:" << players[selectedPlayerToPlay].getSecondCard().GetNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].getSecondCard().GetName() << std::endl;
}

void Game::GetBeginningCards(const int& playerLen)
{
	Card card;

	if (playerLen == 2)
		for (int i = 0; i < 4; i++)
			this->beginningCards.push_back(card.CreateRandom(GetRandomNumber()));
	else
		this->beginningCards.push_back(card.CreateRandom(GetRandomNumber()));
}


