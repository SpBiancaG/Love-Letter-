
#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"

int main()
{//Card* card = new Baron();
	//Card* card2 = new Countess();
	Card* card = new Card();
	Card* card2 = new Card();
	Player* player = new Player("Gicu", card, card2, 0);
	std::vector<Card> cards = { Guard(), Guard(), Guard(), Guard(), Guard(), Priest(), Priest(), Baron(), Baron(), Handmaid(), Handmaid(), Prince(), Prince(), King(), Countess(), Princess() };
	int nrOfCards = 16;
	player->DrawCard(player->GetFirstCard(), nrOfCards, cards);
	std::cout << player->GetFirstCard().getNumber();
	
}

