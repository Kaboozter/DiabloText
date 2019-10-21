#ifndef PLAYER_HEADER
#define PLAYER_HEADER

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

		Player();

		void Update();
		void SetStats(bool aRaceOrClass);

	private:

};
#endif

