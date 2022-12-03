#include "Game.h"

int Game::VerifyNumberOfPlayers(const int32_t&m_nrOfPlayers)
{
	
		if (m_n0OfPlayers >= 2 &&m_nrOfPlayers <= 4)
			returnm_nrOfPlayers;
		else return 0;
	
}

void Game::SetNumberOfPlayers(const int32_t& n0OfPlayers)
{
	
		m_n0OfPlayers = n0OfPlayers;
	
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

	for (int i = 0; i < playerLen; i++) {
		std::string playerName = "";
		Card card;
		std::cout << "Player nr " << i << " name: "; std::cin >> playerName;
		int nr1 = GetRandomNumber();
		int nr2 = GetRandomNumber();
		Player playerAdd(playerName, card.createRandom(availableCards[nr1]), card.createRandom(availableCards[nr2]), 0);

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

std::istream& operator>>(std::istream& in, Game& game)
{
	// TODO: insert return statement here
	in >> (Game&)game;
	in >> game.m_nrOfPlayers;
	in.get();
	game.SetNumberOfPlayers(game.VerifyNumberOfPlayers(game.m_nrOfPlayers));
}
