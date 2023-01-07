#include "Game.h"

#include<vector>
#include<random>

void Game::CheckForCountess(Player* player, int playerLen) {
	if (player->GetFirstCard() != nullptr)
		if (player->GetFirstCard()->GetName() == "Countess")
			player->GetFirstCard()->Action(m_players[selectedPlayer], m_players, playerLen, nrOfPlayersInGame);
		else
			if (player->GetSecondCard() != nullptr)
				if (player->GetSecondCard()->GetName() == "Countess")
					player->GetSecondCard()->Action(m_players[selectedPlayer], m_players, playerLen, nrOfPlayersInGame);

	if (player->GetFirstCard() != nullptr)
		if (player->GetFirstCard()->GetName() == "King" || player->GetFirstCard()->GetName() == "Prince") {
			if (player->GetSecondCard() != nullptr)
				if (player->GetSecondCard()->GetName() == "Countess") {
					player->SetSecondCard(nullptr);
					std::cout << player->GetName() << " draw a Baron/Prince and had to remove the countess" << std::endl;
				}
		}
		else
			if (player->GetSecondCard() != nullptr)
				if (player->GetSecondCard()->GetName() == "King" || player->GetSecondCard()->GetName() == "Prince") {
					if (player->GetFirstCard() != nullptr)
						if (player->GetFirstCard()->GetName() == "Countess") {
							player->SetFirstCard(nullptr);
							std::cout << player->GetName() << " draw a Baron/Prince and had to remove the countess" << std::endl;
						}
				}
}

Game* Game::GetInstance()
{
	
		if (!instance) {
			instance = new Game();
		}
		return instance;
	
}
void Game::PlayerDrawCard(Player* player,int playerLen)
{
	int randomNr = GetRandomNumber();

	if (player->GetFirstCard() == nullptr) {
		player->SetFirstCard(availableCardsAddress[randomNr]->GetInstance());
	}
	else {
		player->SetSecondCard(availableCardsAddress[randomNr]->GetInstance());
	}

	CheckForCountess(player, playerLen);

	if (gameStart) {
		std::cout << "You drew " << availableCardsAddress[randomNr]->GetName() << std::endl;
		player->SetCardsValue(player->GetCardsValue() + availableCardsAddress[randomNr]->GetNumber());
		system("pause");
	}

	availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);
	nrOfCardsInGame--;
}
void Game::GameFirstCards(int& playersLen)
{
	if (playersLen == 2)
		for (int i = 0; i < 4; i++) {
			int randomNr = GetRandomNumber();
			m_beginningCards.push_back(availableCardsAddress[randomNr]);
			availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);
			nrOfCardsInGame--;

		}
	else {
		int randomNr = GetRandomNumber();
		m_beginningCards.push_back(availableCardsAddress[randomNr]);
		availableCardsAddress.erase(availableCardsAddress.begin() + randomNr);
		nrOfCardsInGame--;
	}
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
		Player PlayerAdd(playerName, nullptr, nullptr, 0, false, false, 0);
		m_players.push_back(playerAdd);
		PlayerDrawCard(&m_players[i], playerLen);

	}
	nrOfPlayersInGame = playerLen;
	StartGame(playerLen);
}

int SelectCardToPlay() {
	int key;
	std::cin >> key;
	if (key == 1 || key == 2)
		return key;
	else
	{
		std::cout << "Wrong card selection. Please choose again!" << std::endl;
		SelectCardToPlay();
		return 0;
	}
	return 0;
}










void Game::GetAvailableCardsAddresses()
{
	for (int i = 0; i < 16; i++)
		availableCardsAddress.push_back(&availableCards[i]);
}

void Game::StartGame(int playerLen) {
	while (nrOfCardsInGame > 0 && nrOfPlayersInGame > 1) {

		NextPlayer(playerLen);
		//remove protection on players new round
		if (m_players[selectedPlayer].GetIsProtected())
			m_players[selectedPlayer].SetIsProtected(false);

		if (!m_players[selectedPlayer].GetIsDead())
		{

			PrintGame(playerLen);

			std::cout << "Choose a card to play" << std::endl;
			std::cout << "Choosen card: ";

			if (SelectCardToPlay() == 1) {
				m_players[selectedPlayer].GetFirstCard()->Action(m_players[selectedPlayer], m_players, playerLen, nrOfPlayersInGame);
				m_players[selectedPlayer].SetFirstCard(nullptr);
			}

			else {
				m_players[selectedPlayer].GetSecondCard()->Action(m_players[selectedPlayer], m_players, playerLen, nrOfPlayersInGame);
				m_players[selectedPlayer].SetSecondCard(nullptr);
			}

		}
		else {
			std::cout << m_players[selectedPlayer].GetName() << " is dead." << std::endl;
			system("pause");
		}
	}
	EndGame(playerLen);

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


