#ifndef ITEM_HEADER
#define ITEM_HEADER
#include <string>
#include "Player.h"

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
		TypeManaPotion
	};

	void UseItem(int aType, Player& aPlayer);

	ConsumableItem();
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

	int myStr, mySpeed, myLuck, myAcc;

	Weapons(int aQual, int aType, std::string aName);
	//~Weapons();

	int CalWeaponPot(int aQual, int aType);


private:

};

class Armor : public Item
{
public:
	enum Type
	{
		TypeChestplate,
		TypeHelmet,
		TypeBoots
	};
	Armor();
	~Armor();

private:
};
#endif
