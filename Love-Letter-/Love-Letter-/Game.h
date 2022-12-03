#pragma once
#include"Player.h"
class Game
{private:
	int m_n0OfPlayers;
	Player players[4];
	
public:
	Game()=default;

	int VerifyNumberOfPlayers(const int32_t& m_n0OfPlayers);
	void SetNumberOfPlayers(const int32_t& numberOfPaticipants);
	
	friend std::istream& operator >>(std::istream& in, Game& game);
	void printStartingGame();
    
};

