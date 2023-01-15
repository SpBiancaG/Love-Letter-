#include "Game.h"
#include<random>
#include"Player.h"

void Game::CheckForCountess(Player *player, int playerLen) {
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
		std::cout << "Not enough or too many players. Try again!";
		return;
	}

	GameFirstCards(playerLen);

	for (int i = 0; i < playerLen; i++) {
		std::string playerName = "";
		std::cout << "Player nr " << i << " name: "; std::cin >> playerName;
		Player playerAdd(playerName, nullptr, nullptr, 0, false, false, 0);
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





void Game::StartGame(int playerLen) {
	while (availableCardsAddress.size() > 0 && nrOfPlayersInGame > 1) {

		NextPlayer(playerLen);
		//remove protection on players new round
		if (m_players[selectedPlayer].GetIsProtected())
			m_players[selectedPlayer].SetIsProtected(false);

		if (!m_players[selectedPlayer].GetIsDead())
		{

			PrintGame(playerLen);

			std::cout << "Choose a card to play" << std::endl;
			std::cout << "Choosen card: ";

			if (m_players[selectedPlayer].GetFirstCard() != nullptr && m_players[selectedPlayer].GetSecondCard() != nullptr) {
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
				std::cout << "Skipped round since could not find 2 cards in players' hand" << std::endl;
				system("pause");

			}
		}
		else {
			std::cout << m_players[selectedPlayer].GetName() << " is dead." << std::endl;
			system("pause");
		}
	}
	EndGame(playerLen);

}

int checkCardMaxValue(Player player) {
	//player are prima carte
	if (player.GetFirstCard() != nullptr)
		//player are si a doua carte
		if (player.GetSecondCard() != nullptr)
			//verificam care e mai mare si dam return
			if (player.GetFirstCard()->GetNumber() >= player.GetSecondCard()->GetNumber())
				return player.GetFirstCard()->GetNumber();
			else
				return player.GetSecondCard()->GetNumber();
	//player are DOAR prima carte, deci returnam prima carte
		else return player.GetFirstCard()->GetNumber();
	//player nu are prima carte, o are DOAR pe a doua, deci returnam a doua carte
	else if (player.GetSecondCard() != nullptr)
		return player.GetSecondCard()->GetNumber();
	//Eroare, dam 0
	else return 0;
}

void Game::EndGame(int playerLen) {
	if (nrOfPlayersInGame == 1) {
		for (int i = 0; i < m_players.size(); i++)
			if (!m_players[i].GetIsDead()) {
				m_players[i].SetToken(m_players[i].GetToken() + 1);
				RestartGame(playerLen);
			}
	}

	else if (nrOfPlayersInGame > 1) {

		int max = 0;
		int nrMax = 0;

		for (int i = 0; i < m_players.size(); i++)
			if (max < checkCardMaxValue(m_players[i]) && !m_players[i].GetIsDead()) {
				max = checkCardMaxValue(m_players[i]);
				nrMax = 1;
			}
			else if (max == checkCardMaxValue(m_players[i]) && !m_players[i].GetIsDead())
				nrMax++;

		if (nrMax == 1) {
			for (int i = 0; i < m_players.size(); i++)
				if (max == checkCardMaxValue(m_players[i]) && !m_players[i].GetIsDead()) {
					m_players[i].SetToken(m_players[i].GetToken() + 1);
					RestartGame(playerLen);
				}
		}

		else if (nrMax > 1) {
			int maxCards = 0;

			for (int i = 0; i < m_players.size(); i++)
				if (maxCards < m_players[i].GetCardsValue() && !m_players[i].GetIsDead() && max == checkCardMaxValue(m_players[i]))
					maxCards = m_players[i].GetCardsValue();

			for (int i = 0; i < m_players.size(); i++)
				if (maxCards == m_players[i].GetCardsValue() && !m_players[i].GetIsDead()) {
					m_players[i].SetToken(m_players[i].GetToken() + 1);
					RestartGame(playerLen);
				}
		}
	}
}
bool VerifyWinCondition(Player player, int token, int playerLen, int playerLenSelected) {
	if (player.GetToken() == token && playerLen == playerLenSelected) {
		std::cout << player.GetName() << " won the game with 7 tokens!" << std::endl;
		system("pause");
		return true;
	}
	return false;
}

void Game::RestartGame(int playerLen) {
	GetAvailableCardsAddresses();
	nrOfPlayersInGame = playerLen;
	
	selectedPlayer = -1;
	bool won = false;
	m_beginningCards.clear();
    GameFirstCards(playerLen);

	for (int i = 0; i < m_players.size(); i++) {
		won = VerifyWinCondition(m_players[i], 7, playerLen, 2);
		won = VerifyWinCondition(m_players[i], 5, playerLen, 3);
		won = VerifyWinCondition(m_players[i], 4, playerLen, 4);
		if (won)
			exit;
		m_players[i].SetFirstCard(nullptr);
		m_players[i].SetSecondCard(nullptr);
		m_players[i].SetIsDead(false);
		selectedPlayer++;
		PlayerDrawCard(&m_players[i], playerLen);
	}
	selectedPlayer = -1;
	StartGame(playerLen);
}

void Game::PrintRecicleCards(int& playerLen) {
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


void Game::PrintGame(int& playerLen)
{
	system("cls");

	for (int i = 0; i < m_players.size(); i++) {
		std::cout << m_players[i].GetName() << "\t" << m_players[i].GetToken() << "\t";
		if (m_players[i].GetIsDead())
			std::cout << "Dead" << std::endl;
		else
			std::cout << "Alive" << std::endl;
	}

	std::cout << std::endl;

	PrintRecicleCards(playerLen);

	std::cout << m_players[selectedPlayer].GetName() << "'s turn" << std::endl << std::endl;
	if (m_players[selectedPlayer].GetFirstCard() != nullptr) {
		std::cout << "First Card:" << m_players[selectedPlayer].GetFirstCard()->GetNumber() << "\t";
		std::cout << m_players[selectedPlayer].GetFirstCard()->GetName() << "\t";
		std::cout << m_players[selectedPlayer].GetFirstCard()->GetDescription() << std::endl;
	}
	else
		std::cout << "No First Card" << std::endl;
	if (m_players[selectedPlayer].GetSecondCard() != nullptr) {
		std::cout << "Second Card:" << m_players[selectedPlayer].GetSecondCard()->GetNumber() << "\t";
		std::cout << m_players[selectedPlayer].GetSecondCard()->GetName() << "\t";
		std::cout << m_players[selectedPlayer].GetSecondCard()->GetDescription() << std::endl;
	}
	else
		std::cout << "No Second Card" << std::endl;

}
void Game::NextPlayer(int playerLen) {

	if (selectedPlayer == nrOfPlayersInGame - 1)
		selectedPlayer = -1;

	selectedPlayer++;
	if (!m_players[selectedPlayer].GetIsDead()) {
		PlayerDrawCard(&m_players[selectedPlayer], playerLen);
		std::cout << m_players[selectedPlayer].GetName() << " drew a card" << std::endl;
	}
	gameStart = true;
}

void Game::GetAvailableCardsAddresses() {
	availableCardsAddress.clear();
	for (int i = 0; i < 16; i++)
		availableCardsAddress.push_back(availableCards[i]);
}


