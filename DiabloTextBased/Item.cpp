#include "Item.h"


int Weapons::CalWeaponPot(int aQuality, int aType)
{
	int tempPot;
	if (aType == Weapons::TypeSword)
	{
		tempPot = aQuality * 20;
	}
	if (aType == Weapons::TypeBow)
	{
		tempPot = aQuality * 15;
	}
	if (aType == Weapons::TypeHammer)
	{
		tempPot = aQuality * 25;
	}

	return tempPot;
}
