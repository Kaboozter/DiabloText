#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include <iostream>

class Enemy
{
	public:
		int myHp, myAttack, myDef, myAcc, mySpeed;
		int myXpGive, myLevel;
		std::string myName;
		std::string myNames [8];

		Enemy(int aLevelOfEnemy);
		~Enemy();

	private:


};
#endif
