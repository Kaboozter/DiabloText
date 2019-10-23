#include "Enemy.h"
#include "Log.h"

std::string* myNames = new std::string[8]{ "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan Löfven" };

//std::string myNames[8] = { "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan Löfven" };

Enemy::Enemy(int aLevelOfEnemy)
{
	myName = myNames[(aLevelOfEnemy - 1)];
	myAttack = aLevelOfEnemy * aLevelOfEnemy;
}

Enemy::~Enemy()
{
	
}

