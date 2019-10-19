#include "Player.h"
#include <iostream>

Player::Player() {
	myRace = Elf;
	myStr = 0, mySpeed = 0, myLuck = 0, myDef = 0, myAcc = 0;
}

void Player::Update() {


}

void Player::SetStats()
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


