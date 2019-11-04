#include "Item.h"


int Weapons::CalWeaponPot(int aQuality, int aType)
{
	if (aType == Weapons::TypeSword)
	{
		return (aQuality + 1) * 20;
	}
	if (aType == Weapons::TypeBow)
	{
		return (aQuality + 1) * 15;
	}
	if (aType == Weapons::TypeHammer)
	{
		return (aQuality + 1) * 25;
	}
}

Weapons::Weapons(int aQual, int aType, std::string aName)
{
	myQuality = aQual;
	myType = aType;
	myName = aName;
	myPotency = CalWeaponPot(myQuality, myType);
}

void ConsumableItem::UseItem(int aType, Player& aPlayer) 
{
	if (aType == ConsumableItem::TypeHealthPotion) {
		aPlayer.myHp += myPotency;
	}
}