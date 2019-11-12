#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Item.h"

class Item;
class Weapons;
class Materials;

class Player
{
	public:
		enum Race
		{
			Human,
			Dwarf,
			Elf,
			Halfling
		};
		float myStr, mySpeed, myLuck, myDef, myAcc;
		float myHp, myMaxHp, myLevel, myXp;
	    int myRace, myClass;

		ConsumableItem myPotion;
		Weapons* myInventory;
		Materials* myMaterialInventory;

		void LevelUp();

		Player();
		~Player();

		void Update();
		void SetStats(bool aRaceOrClass);

	private:

};
#endif

