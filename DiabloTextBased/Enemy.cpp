#include "Enemy.h"

std::string myNames[8] = { "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan L�fven" };

Enemy::Enemy(int aLevelOfEnemy)
{
	myName = myNames[(aLevelOfEnemy - 1)];
}

