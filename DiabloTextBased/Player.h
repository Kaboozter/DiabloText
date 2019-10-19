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
		int myHealth, myLevel, myXp;
	    int myRace;

		Player();

		void Update();
		void SetStats();

	private:

};
#endif

