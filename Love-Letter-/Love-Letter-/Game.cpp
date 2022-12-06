#include "Game.h"
#include "Player.h"
void Game::NextPlayer()
{
	
		this->selectedPlayerToPlay++;
		Card card = card.CreateRandom(GetRandomNumber());
		if (players[selectedPlayerToPlay].GetFirstCard().GetName()._Equal(""))
			players[selectedPlayerToPlay].SetFirstCard(players[selectedPlayerToPlay].GetSecondCard());
		players[selectedPlayerToPlay].SetSecondCard(card);
		std::cout << players[selectedPlayerToPlay].GetName() << " drew " << card.GetName();

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
		std::cout << "Player number " << i << " Name: "; std::cin >> playerName;
		Player playerAdd(playerName, card.CreateRandom(GetRandomNumber()), card, 0);
		std::cout << playerAdd.GetSecondCard().GetName();
		this->players.push_back(playerAdd);
	}
	NextPlayer();
	
	PrintGame(playerLen);
	int key;
	std::cin >> key;
	NextPlayer();
	PrintGame(playerLen);

}




void Game::PrintStartingGame()
{
	std::cout << players[selectedPlayerToPlay].GetName() << "'s turn" << std::endl << std::endl;
	std::cout << "First Card:" << players[selectedPlayerToPlay].GetFirstCard().GetNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].GetFirstCard().GetName() << std::endl;
	std::cout << "Second Card:" << players[selectedPlayerToPlay].GetSecondCard().GetNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].GetSecondCard().GetName() << std::endl;
}
void PrintGame(int& playerLen) {
	system("cls");

	if (playerLen != 2) {
		std::cout << "TOP CARD" <<std:: endl << beginningCards[0].getNumber() << " " << beginningCards[0].getName() << std::endl << std::endl;
	}
	else {
		std::cout << "TOP CARDS" <<std:: endl;
		for (int i = 0; i < 4; i++)
			std::cout << beginningCards[i].getNumber() << " " << beginningCards[i].getName() <<std:: endl;
		std::cout << std::endl << std::endl;
	}
	std::cout << players[selectedPlayerToPlay].getName() << "'s turn" << std::endl << std::endl;
	std::cout << "First Card:" << players[selectedPlayerToPlay].getFirstCard().getNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].getFirstCard().getName() << std::endl;
	std::cout << "Second Card:" << players[selectedPlayerToPlay].getSecondCard().getNumber();
	std::cout << "     ";
	std::cout << players[selectedPlayerToPlay].getSecondCard().getName() << std::endl;
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


