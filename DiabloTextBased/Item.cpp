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

Weapons::Weapons()
{
	myQuality = 0;
	myType = 0;
	myName = " ";
	myStr = 0;
	mySpeed = 0;
	myLuck = 0;
	myDef = 0;
	myAcc = 0;
}

Weapons::~Weapons()
{

}

void Weapons::CreateWeapon(int aQual, int aType, std::string aName)
{
	myQuality = aQual;
	myType = aType;
	myName = aName;
	myPotency = CalWeaponPot(myQuality, myType);
}

void Weapons::SetAttribute(int aStr, int aSpeed, int aLuck, int aDef, int aAcc)
{
	myStr = aStr;
	mySpeed = aSpeed;
	myLuck = aLuck;
	myDef = aDef;
	myAcc = aAcc;
}



ConsumableItem::ConsumableItem() {
	myAmount = 0;
}
ConsumableItem::~ConsumableItem()
{

}

void ConsumableItem::GiveQuality(int aQual)
{
	myPotency = ((aQual + 1) * 0.25f);
}

Materials::Materials() {
	myAmount = 0;
	myResultName1 = " ", myResultName2 = " ";
	myStr = 0, mySpeed = 0, myLuck = 0, myDef = 0, myAcc = 0;
}

Materials::~Materials()
{

}

void Materials::CreateMaterial(int aType)
{
	myType = aType;
	if (myType == 0)
	{
		myName = "Goblin Tooth";
		myResultName1 = "Skullcrusher";
		myResultName2 = "Skinflayer";
		myStr = 3;
		mySpeed = 0;
		myLuck = 0;
		myDef = 3;
		myAcc = 0;
		myQuality = 0;
	}
	if (myType == 1)
	{
		myName = "Wolf Pelt";
		myResultName1 = "Wild Hunt";
		myResultName2 = "Lone Wolf";
		myStr = 6;
		mySpeed = 3;
		myLuck = 0;
		myDef = 6;
		myAcc = 0;
		myQuality = 0;
	}
	if (myType == 2)
	{
		myName = "Ogre Bones";
		myResultName1 = "Stonebreaker";
		myResultName2 = "Jawbone";
		myStr = 9;
		mySpeed = -3;
		myLuck = 0;
		myDef = 9;
		myAcc = 0;
		myQuality = 1;
	}
	if (myType == 3)
	{
		myName = "Giant head";
		myResultName1 = "Devourer";
		myResultName2 = "Gatecrasher";
		myStr = 12;
		mySpeed = 0;
		myLuck = 0;
		myDef = 9;
		myAcc = 0;
		myQuality = 2;
	}
	if (myType == 4)
	{
		myName = "Dragon Scales";
		myResultName1 = "The Untamed, Katana of Invocation";
		myResultName2 = "Draughtbane, Incarnation of the Night Sky";
		myStr = 12;
		mySpeed = 12;
		myLuck = 12;
		myDef = 12;
		myAcc = 12;
		myQuality = 2;
	}
	if (myType == 5)
	{
		myName = "Divine Spark";
		myResultName1 = "Destiny's Song, Dark Blade of the Champion";
		myResultName2 = "Stormbringer, Warblade of the Earth";
		myStr = 18;
		mySpeed = 18;
		myLuck = 18;
		myDef = 18;
		myAcc = 18;
		myQuality = 3;
	}
	if (myType == 6)
	{
		myName = "Draconic Core";
		myResultName1 = "Doombringer, Hope of Time-Lost Memories";
		myResultName2 = "Deathraze, Defender of Timeless Battles";
		myStr = 30;
		mySpeed = 30;
		myLuck = 30;
		myDef = 30;
		myAcc = 30;
		myQuality = 3;
	}
}