#include "Enemy.h"
#include "Log.h"



Enemy::Enemy(int aLevelOfEnemy, bool aBoss)
{
	myNames = new std::string[7]{ "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God"};
	myBossNames = new std::string[7]{ "Boblin the Goblin Cheiftain", "Silvertooth the direworlf",
		"Shrek of the dreaded swamp", "Yorm of the profaned capital", "Ancalagon the black", "Omus, God Of Triumph",
	"Tiamat, progenitor of evil" };
	myIsBoss = aBoss;
	if (aBoss) {
		myName = myBossNames[(aLevelOfEnemy - 1)];
		myAttack = aLevelOfEnemy * aLevelOfEnemy * aLevelOfEnemy * 10;
		myHp = aLevelOfEnemy * aLevelOfEnemy* aLevelOfEnemy * 10;
		myXpGive = aLevelOfEnemy * 1000;
	}
	else if (!aBoss)
	{
		myName = myNames[(aLevelOfEnemy - 1)];
		myAttack = aLevelOfEnemy * aLevelOfEnemy * 10;
		myHp = aLevelOfEnemy * aLevelOfEnemy * 10;
		myXpGive = aLevelOfEnemy * 100;
	}
	myAttackPhrase = "You Are Fighting " + myName;

}

Enemy::~Enemy()
{
	delete[](myNames);
	delete[](myBossNames);
}


