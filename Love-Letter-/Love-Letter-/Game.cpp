#include "Game.h"
#include "Player.h"
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
		Card card = card.CreateRandom(GetRandomNumber());
		if (m_players[m_selectedPlayerToPlay].GetFirstCard().GetName()._Equal(""))
			m_players[m_selectedPlayerToPlay].SetFirstCard(m_players[m_selectedPlayerToPlay].GetSecondCard());
		m_players[m_selectedPlayerToPlay].SetSecondCard(card);
		std::cout <<m_players[m_selectedPlayerToPlay].GetName() << " drew " << card.GetName();

}

int Game::GetRandomNumber()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, m_availableCardsLen); // define the range
	int randomNr = distr(gen);
	for (int i = randomNr; i < m_availableCardsLen; ++i)
		m_availableCards[i] = m_availableCards[i + 1];
	m_availableCards[m_availableCardsLen] = 0;
	m_availableCardsLen--;
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
		this->m_players.push_back(playerAdd);
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
	std::cout <<m_players[m_selectedPlayerToPlay].GetName() << "'s turn" << std::endl << std::endl;
	std::cout << "First Card:" << m_players[m_selectedPlayerToPlay].GetFirstCard().GetNumber();
	std::cout << "     ";
	std::cout << m_players[m_selectedPlayerToPlay].GetFirstCard().GetName() << std::endl;
	std::cout << "Second Card:" << m_players[m_selectedPlayerToPlay].GetSecondCard().GetNumber();
	std::cout << "     ";
	std::cout << m_players[m_selectedPlayerToPlay].GetSecondCard().GetName() << std::endl;
}


void Game::GetBeginningCards( int& playerLen)
{
	Card card;

	if (playerLen == 2)
		for (int i = 0; i < 4; i++)
			this->m_beginningCards.push_back(card.CreateRandom(GetRandomNumber()));
	else
		this->m_beginningCards.push_back(card.CreateRandom(GetRandomNumber()));
}

void Game::PrintGame(int& playerLen)
{
	system("cls");

	if (playerLen != 2) {
		std::cout << "TOP CARD" << std::endl << m_beginningCards[0].GetNumber() << " " << m_beginningCards[0].GetName() << std::endl << std::endl;
	}
	else {
		std::cout << "TOP CARDS" << std::endl;
		for (int i = 0; i < 4; i++)
			std::cout << m_beginningCards[i].GetNumber() << " " << m_beginningCards[i].GetName() << std::endl;
		std::cout << std::endl << std::endl;
	}
	std::cout << m_players[m_selectedPlayerToPlay].GetName() << "'s turn" << std::endl << std::endl;
	std::cout << "First Card:" << m_players[m_selectedPlayerToPlay].GetFirstCard().GetNumber();
	std::cout << "     ";
	std::cout << m_players[m_selectedPlayerToPlay].GetFirstCard().GetName() << std::endl;
	std::cout << "Second Card:" << m_players[m_selectedPlayerToPlay].GetSecondCard().GetNumber();
	std::cout << "     ";
	std::cout << m_players[m_selectedPlayerToPlay].GetSecondCard().GetName() << std::endl;
}


