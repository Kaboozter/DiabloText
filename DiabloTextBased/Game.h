#pragma once
#include "Player.h";
#include "Log.h";

class Game
{
public:
	void Initialize();
	void Update();
	void DisplayStats(Player aPlayer, Log aLog);

};

