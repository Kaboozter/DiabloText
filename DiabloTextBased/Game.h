#ifndef GAME_HEADER
#define GAME_HEADER
#include "Player.h";
#include "Log.h";

class Game
{
public:
	void Initialize();
	void Update(Player& aPlayer, Log aLog);
	void DisplayStats(Player& aPlayer, Log aLog, bool someOnlyStats);
	bool YesNo(Log aLog);
};

#endif

