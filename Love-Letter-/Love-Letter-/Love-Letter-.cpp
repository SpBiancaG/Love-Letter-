
#include"Game.h"


Game* Game::instance = nullptr;


int main() {
	Game::GetInstance()->SetStartingPlayers();
}

