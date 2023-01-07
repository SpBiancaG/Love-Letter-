#pragma once

class Handmaid :
    public Card
{
public:
	Handmaid() : Card{ "Handmaid", 4, "Until your next turn, ignore all effects from other players' cards." } {};

	Handmaid(std::string name, int number, std::string description);

	Handmaid(const Handmaid& handmaid) { *this = handmaid; };

	void Action(Player& player, std::vector<Player>& players, int playersLen, int& nrOfPlayersInGame);
	

	Card* GetInstance() { return new Handmaid(*this); };
};

  