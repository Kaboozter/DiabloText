#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include <iostream>
#include "Player.h"

class Enemy
{
	public:
		float myHp, myAttack, myDef, myAcc, mySpeed;
		int myXpGive, myLevel;
		bool myIsBoss;
		std::string myName;
		std::string* myNames, *myBossNames;
		std::string myAttackPhrase;

		void EnemyTurn(Player& aPlayer, Log& aLog) {
			if (aPlayer.myHp < myAttack) {
				aPlayer.myHp -= (myAttack * (1 - (aPlayer.myDef / 40)));
			}
			else if (myHp < (myHp/5)) {
				myDef = (myDef * 1.5f);
			}
			else {
				aPlayer.myHp -= (myAttack * (1 - (aPlayer.myDef / 40)));
			}
		}

		Enemy(int aLevelOfEnemy, bool aBoss);
		~Enemy();

	private:

};
#endif
