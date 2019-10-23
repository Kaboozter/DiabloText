#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Item.h";

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
		int myStr, mySpeed, myLuck, myDef, myAcc;
		int myHp, myMaxHp, myLevel, myXp;
	    int myRace, myClass;

		Item* items;

		Player();
		~Player();

		void Update();
		void SetStats(bool aRaceOrClass);

	private:

};
#endif

