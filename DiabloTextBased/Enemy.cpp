#include "Enemy.h"
#include "Log.h"

std::string* myNames = new std::string[8]{ "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan L�fven" };

//std::string myNames[8] = { "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan L�fven" };

Enemy::Enemy(int aLevelOfEnemy)
{
	myName = myNames[(aLevelOfEnemy - 1)];
	myAttack = aLevelOfEnemy * aLevelOfEnemy;
}

Enemy::~Enemy()
{
	
}

