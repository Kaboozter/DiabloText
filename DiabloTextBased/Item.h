#ifndef ITEM_HEADER
#define ITEM_HEADER
#include <string>
#include "Player.h"
#include "Log.h"

class Player;

class Item
{
	public:
		enum Quality
		{
			QCommon,
			QUncommon,
			QRare,
			QLegendary
		};

		std::string myName = " ";
		int myType, myQuality, myPotency;


	private:

};

class ConsumableItem : public Item
{
public:
	enum Type
	{
		TypeHealthPotion,
	};

	void UseItem(Player& aPlayer);

	int myAmount;

	ConsumableItem(int aQual);
	~ConsumableItem();

private:
};

class Weapons : public Item
{
public:
	enum Type
	{
		TypeSword,
		TypeBow,
		TypeHammer
	};

	int myStr, mySpeed, myLuck, myDef, myAcc;

	void CreateWeapon();

	Weapons(int aQual, int aType, std::string aName);
	~Weapons();

	int CalWeaponPot(int aQual, int aType);


private:

};

class Materials : public Item
{
public:
	enum Type
	{
		GoblinTooth,
		WolfPelt,
		OgreBones,
		GiantHead,
		DragonScales,
		DivineSpark,
		DraconicCore
	};

	std::string myResultName1, myResultName2;
	float myStr, mySpeed, myLuck, myDef, myAcc;
	int myAmount;

	Materials(int aType);
	~Materials();

private:
};

#endif
