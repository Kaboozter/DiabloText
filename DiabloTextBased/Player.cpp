#include "Player.h"
#include <iostream>


Player::Player() {
	myRace = Elf;
	myLevel = 1, myXp = 100;
	myMaxHp = myLevel * 30, myHp = myMaxHp;
	myClass = 0;
	myStr = 0, mySpeed = 0, myLuck = 0, myDef = 0, myAcc = 0;
	myDead = false;
	myInventory = new Weapons[7];
	myMaterialInventory = new Materials[7];
	myPotion = ConsumableItem();
	myPotion.GiveQuality(0);
	myEquipedWeapon = Weapons();
}

Player::~Player()
{
	delete[](myInventory);
}

void Player::Update() {
	
}

void Player::SetStats(bool aRaceOrClass)
{
	if (aRaceOrClass) 
	{
		switch (myRace)
		{
		case Human:
			myStr = 1;
			mySpeed = 3;
			myAcc = 4;
			myDef = 2;
			myLuck = 5;
			break;
		case Dwarf:
			myStr = 5;
			mySpeed = 1;
			myAcc = 2;
			myDef = 4;
			myLuck = 3;
			break;
		case Elf:
			myStr = 3;
			mySpeed = 4;
			myAcc = 5;
			myDef = 1;
			myLuck = 2;
			break;
		case Halfling:
			myStr = 1;
			mySpeed = 2;
			myAcc = 5;
			myDef = 3;
			myLuck = 4;
			break;
		}

	}
	else if (!aRaceOrClass) 
	{
		switch (myClass)
		{
		case 0:
			myStr += 3;
			mySpeed += 1;
			myAcc += 0;
			myDef += 2;
			myLuck += 0;
			break;
		case 1:
			myStr += 0;
			mySpeed += 2;
			myAcc += 1;
			myDef += 0;
			myLuck += 3;
			break;
		case 2:
			myStr += 1;
			mySpeed += 2;
			myAcc += 3;
			myDef += 0;
			myLuck += 0;
			break;
		}
	}
}

void Player::UsePotion(Log& aLog)
{
	if (myPotion.myAmount > 0)
	{
		myHp += (myMaxHp * myPotion.myPotency);
		myPotion.myAmount--;
		aLog.Write(std::to_string(myPotion.myAmount) + " Potions Left");
	}
	else
	{
		aLog.Write("Not enough potions");
	}
}

void Player::LevelUp() {
	myMaxHp = myLevel * 30;
	myHp = myMaxHp;
	myStr += 1, mySpeed += 1, myLuck += 1, myDef += 1, myAcc += 1;
}

