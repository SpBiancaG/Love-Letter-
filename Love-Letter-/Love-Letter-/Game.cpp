#include "Game.h"
#include "Player.h"
#include<vector>
#include<random>
void Game::PlayerDrawCard(Player* player)
{
	int randomNr = GetRandomNumber();

	if (player->GetFirstCard()->GetName() == "")
		player->SetFirstCard(availableCardsAddress[randomNr]);
	else
		player->SetSecondCard(availableCardsAddress[randomNr]);

	availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);
}
void Game::GameFirstCards(int& playersLen)
{
	if (playersLen == 2)
		for (int i = 0; i < 4; i++) {
			int randomNr = GetRandomNumber();
			m_beginningCards.push_back(availableCardsAddress[randomNr]);
			availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);

		}
	else {
		int randomNr = GetRandomNumber();
		m_beginningCards.push_back(availableCardsAddress[randomNr]);
		availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);
	}
}
void Game::NextPlayer()
{
	
	this->m_selectedPlayerToPlay++;
	PlayerDrawCard(&m_players[m_selectedPlayerToPlay]);
	std::cout << m_players[m_selectedPlayerToPlay].GetName() << " drew a card" << std::endl;

}

int Game::GetRandomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, availableCardsAddress.size() - 1); // define the range
	return distr(gen);
}

void Game::SetStartingPlayers()
{
	GetAvailableCardsAddresses();

	int playerLen = 0;
	std::cout << "Number of players: "; std::cin >> playerLen;

	if (playerLen < 2 || playerLen>4) {
		std::cout << "Not enough players. Try again!";
		return;
	}

	GameFirstCards(playerLen);

	for (int i = 0; i < playerLen; i++) {
		std::string playerName = "";
		std::cout << "Player nr " << i << " name: "; std::cin >> playerName;
		Player playerAdd(playerName, new Card(), new Card(), 0);
		m_players.push_back(playerAdd);
		PlayerDrawCard(&m_players[i]);

	}

	NextPlayer();
	PrintGame(playerLen);
	int key;
	std::cin >> key;
	NextPlayer();
	PrintGame(playerLen);
}






void Game::GetAvailableCardsAddresses()
{
	for (int i = 0; i < 16; i++)
		availableCardsAddress.push_back(&availableCards[i]);
}

void Game::Test()
{
	GetAvailableCardsAddresses();
	Card* card = new Card();
	//card = availableCardsAddress[0];
	std::cout << card->GetName();
}




void Game::PrintGame(int& playerLen)
{
	system("cls");

	PrintRecicleCards(playerLen);

	std::cout << m_players[m_selectedPlayerToPlay].GetName() << "' turn" << std::endl << std::endl;
	std::cout << "First Card:" << m_players[m_selectedPlayerToPlay].GetFirstCard()->GetNumber() << "\t";
	std::cout << m_players[m_selectedPlayerToPlay].GetFirstCard()->GetName() << std::endl;
	std::cout << "Second Card:" << m_players[m_selectedPlayerToPlay].GetSecondCard()->GetNumber() << "\t";
	std::cout << m_players[m_selectedPlayerToPlay].GetSecondCard()->GetName() << std::endl;
}

void Game::PrintRecicleCards(int& playerLen)
{
	if (playerLen != 2) {
		std::cout << "TOP CARD" << std::endl << m_beginningCards[0]->GetNumber() << " " << m_beginningCards[0]->GetName() << std::endl << std::endl;
	}
	else {
		std::cout << "TOP CARDS" << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << m_beginningCards[i]->GetNumber() << " " << m_beginningCards[i]->GetName() << std::endl;
		std::cout << std::endl << std::endl;
	}
}


