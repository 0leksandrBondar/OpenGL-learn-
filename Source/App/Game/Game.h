#pragma once

#include "../Singleton/ISingleton.h"

class Game : public ISingleton<Game>
{
public:
	Game() = default;
	~Game();

	void startGameLoop();
};
