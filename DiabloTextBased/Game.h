#ifndef GAME_HEADER
#define GAME_HEADER
#include "Player.h"
#include "Log.h"
#include "Room.h"

class Game
{
public:
	void Initialize();
	void Update(Player& aPlayer, Log& aLog);
	void DisplayStats(Player& aPlayer, Log& aLog, bool someOnlyStats);
	void Fight(Player& aPlayer, Log& aLog, bool aBoss);
	void Craft(Player& aPlayer, Log& aLog, int aCurrSpace);
	void EquipWeapon(Player& aPlayer, Log& aLog, Weapons aWeapon);
	bool YesNo(Log& aLog);

	int myCurrRoom, myCurrStage;

	Room* myRooms;
};

#endif

