#pragma once

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
	static Game* instance;                            // (1)
	Game() = default;
	~Game() = default;

	int m_nrOfPlayers;
	std::vector<Player> m_players;
	std::vector<Card*> m_beginningCards;
	
	std::vector<Card*> availableCards = {new Guard(),new Guard(),new Guard(),new Guard(),new Guard(),new Priest(),new Priest(),new Baron(),new Baron(),new Handmaid(),new Handmaid(),new Prince(),new Prince(),new King(),new Countess(),new Princess()};
	std::vector<Card*> availableCardsAddress;
	int m_selectedPlayer = -1;
	int nrOfCardsInGame = 16;
	int nrOfPlayersInGame = 0;
	bool gameStart = false;

public:
	
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game* GetInstance();
		
	
	void PlayerDrawCard(Player* player, int playerLen);

	void GameFirstCards(int& playersLen);

	void NextPlayer(int playerLen);

	void SetStartingPlayers();

	void PrintGame(int& playerLen);

	void PrintRecicleCards(int& playerLen);

	int GetRandomNumber();
	
	void GetAvailableCardsAddresses();

	void StartGame(int playerLen);

	void RestartGame(int playerLen);

	void CheckForCountess(Player* player, int playerLen);

	void EndGame(int playerLen);
	
	

	
	
    
};

