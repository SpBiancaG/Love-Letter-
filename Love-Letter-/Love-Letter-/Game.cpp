#include "Game.h"

int Game::VerifyNumberOfPlayers(const int32_t& m_n0OfPlayers)
{
	
		if (m_n0OfPlayers >= 2 && m_n0OfPlayers <= 4)
			return m_n0OfPlayers;
		else return 0;
	
}

void Game::SetNumberOfPlayers(const int32_t& n0OfPlayers)
{
	
		m_n0OfPlayers = n0OfPlayers;
	
}

void Game::printStartingGame()
{
}

std::istream& operator>>(std::istream& in, Game& game)
{
	// TODO: insert return statement here
	in >> (Game&)game;
	in >> game.m_n0OfPlayers;
	in.get();
	game.SetNumberOfPlayers(game.VerifyNumberOfPlayers(game.m_n0OfPlayers));
}
