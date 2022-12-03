#pragma once
#include"Player.h"
#include"Card.h"
class Game
{private:
	int m_nrOfPlayers;
	std::vector<Player> players;
	int availableCards[16] = { 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8 };
	int availableCardsLen = 15;
	int selectedPlayerToPlay = 0;
public:
	Game()=default;

	
	int VerifyNumberOfPlayers(const int32_t& m_nrOfPlayers);
	void SetNumberOfPlayers(const int32_t& numberOfPaticipants);
	int GetRandomNumber();
	void SetStartingPlayers();
	void PrintStartingGame();

	friend std::istream& operator >>(std::istream& in, Game& game);
	
    
};

