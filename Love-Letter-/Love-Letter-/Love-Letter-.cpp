
#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
Game* Game::instance = nullptr;
int main()
{
	Game::GetInstance()->SetStartingPlayers();
	//game.test();
	//std::vector<Player> players;
	//Card* card = new Card();
	Card* card2 = new Guard();
	Card* card3 = new Countess();
	
}

