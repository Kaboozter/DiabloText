#include "Enemy.h"

std::string myNames[8] = { "Goblin", "Wolf", "Ogre", "Giant", "Dragon", "God", "Dragon-God", "Stefan Löfven" };

Enemy::Enemy(int aLevelOfEnemy)
{
	myName = myNames[(aLevelOfEnemy - 1)];
}

