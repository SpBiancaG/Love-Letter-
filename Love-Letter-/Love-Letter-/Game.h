#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"Player.h"
#include"Card.h"
class Game
{private:
	int m_nrOfPlayers;
	std::vector<Player> players;
	std::vector<Card> beginningCards;
	int availableCards[16] = { 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 8 };
	int availableCardsLen = 15;
	int selectedPlayerToPlay = 0;
public:
	Game()=default;

	
	
	void NextPlayer();
	int GetRandomNumber();
	void SetStartingPlayers();
	void PrintStartingGame();
	void GetBeginningCards(const int& playerLen);

	
	
    
};

