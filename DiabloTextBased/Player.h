#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Item.h"

class Item;
class Materials;
class ConsumableItem;

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
		bool myDead;

		ConsumableItem myPotion;
		Weapons* myInventory, myEquipedWeapon;
		Materials* myMaterialInventory;

		void UsePotion(Log& aLog);

		void LevelUp();

		Player();
		~Player();

		void Update();
		void SetStats(bool aRaceOrClass);

	private:

};
#endif

