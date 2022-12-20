#pragma once
#include<string>
#include<vector>
#include<iostream>


#include "Player.h"
#include "Baron.h"
#include "Countess.h"
#include "Guard.h"
#include "Handmaid.h"
#include "King.h"
#include "Priest.h"
#include "Prince.h"
#include "Princess.h"
class Game
{private:
	uint8_t m_nrOfPlayers;
	std::vector<Player> m_players;
	std::vector<Card> m_beginningCards;
	
	std::vector<Card> availableCards = { Guard(), Guard(), Guard(), Guard(), Guard(), Priest(), Priest(), Baron(), Baron(), Handmaid(), Handmaid(), Prince(), Prince(), King(), Countess(), Princess() };
	std::vector<Card*> availableCardsAddress;
	int m_selectedPlayerToPlay = -1;
public:
	
	Game() = default;
	void PlayerDrawCard(Player* player);
	void GameFirstCards(int& playersLen);
	void NextPlayer();
	void SetStartingPlayers();
	void PrintGame(int& playerLen);
	void PrintRecicleCards(int& playerLen);
	int GetRandomNumber();
	
	void GetAvailableCardsAddresses();

	void Test();
	
	

	
	
    
};

