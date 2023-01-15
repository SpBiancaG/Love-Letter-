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
	static Game* m_instance;                            
	Game() = default;
	~Game() = default;

	
	std::vector<Player> m_players;
	std::vector<Card*> m_beginningCards;
	
	std::vector<Card*> m_availableCards = { new Guard(), new Guard(), new Guard(), new Guard(), new Guard(), new Priest(), new Priest(), new Baron(), new Baron(), new Handmaid(), new Handmaid(), new Prince(), new Prince(), new King(), new Countess(), new Princess() };
	std::vector<Card*> m_availableCardsAddress;
	int m_selectedPlayer = -1;
	int m_nrOfPlayersInGame = 0;
	bool m_gameStart = false;

public:
	
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	static Game* GetInstance();
		
	
	void PlayerDrawCard(Player* player, int playerLen, bool isPrinceAction);

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

