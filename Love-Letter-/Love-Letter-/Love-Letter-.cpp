
#include"Game.h"


Game* Game::m_instance = nullptr;


int main() {
	Game::GetInstance()->SetStartingPlayers();
}

