#include "King.h"
#include"Player.h"
#include "Card.h"
template <class Card>
void SwapCards(Card* card1, Card* card2) {
	Card tmp(std::move(*card1));
	*card1 = std::move(*card2);
	*card2 = std::move(tmp);
}

King::King(const King& king)
{
	*this = king;
}

void King::Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame) {
	int responsePlayer;

	PrintPlayers(player, players, responsePlayer, playersLen, false);
	if (responsePlayer == -1)
		return;

	if (player.GetFirstCard()->GetName() == "King")
		if (players[responsePlayer].GetFirstCard() != nullptr)
			SwapCards(player.GetSecondCard(), players[responsePlayer].GetFirstCard());
		else
			SwapCards(player.GetSecondCard(), players[responsePlayer].GetSecondCard());
	else
		if (players[responsePlayer].GetFirstCard() != nullptr)
			SwapCards(player.GetFirstCard(), players[responsePlayer].GetFirstCard());
		else
			SwapCards(player.GetFirstCard(), players[responsePlayer].GetSecondCard());
	system("pause");
}

Card* King::GetInstance()
{
	return new King(*this);
}
