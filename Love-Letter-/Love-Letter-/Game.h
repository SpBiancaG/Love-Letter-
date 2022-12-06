#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<array>
#include"Player.h"
#include"Card.h"
class Game
{private:
	uint8_t m_nrOfPlayers;
	std::vector<Player> m_players;
	std::vector<Card> m_beginningCards;
	uint8_t m_availableCards[16] = { 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8 };
	uint8_t m_availableCardsLen = 15;
	int m_selectedPlayerToPlay = -1;
public:
	Game()=default;

	
	
	void NextPlayer();
	int GetRandomNumber();
	void SetStartingPlayers();
	void PrintStartingGame();
	void GetBeginningCards(const int& playerLen);
	void PrintGame(int& playerLen);
	

	
	
    
};

