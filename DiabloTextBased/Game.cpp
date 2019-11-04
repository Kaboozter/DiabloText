#include <iostream>
#include <conio.h>
#include <vector>
#include "Game.h"
#include "item.h"
#include "Enemy.h"
#include "Player.h"
#include "Log.h"
#include "Room.h"

std::string myInput;

//Player::Race hash(std::string aInString)
//{
//	if (aInString == "Human" || aInString == "human") return Player::Human;
//	else if (aInString == "Dwarf" || aInString == "dwarf") return Player::Dwarf;
//	else if (aInString == "Elf" || aInString == "elf") return Player::Elf;
//	else if (aInString == "Halfling" || aInString == "halfling") return Player::Halfling;
//}

bool myLoop = true;

void Game::Initialize()
{
	Player myPlayer;
	Log myLog;
	Weapons myWeapon(0, rand() % 3 + 1, "Starter");
	//myRooms = new Room[15]{
	//	myRooms[0] = Room(1,2);
	//	for (int i = 1; i < 14; i++)
	//	{
	//		myRooms[i] = Room(rand() % 3, rand() % 3 + 1);
	//	}
	//};

	
	myPlayer.myItems[0] = myWeapon;

	//myRooms[0] = Room();
	//for (int i = 1; i < std::count(myRooms); i++)
	//{

	//}

	while (myLoop)
	{
		switch (myLog.MultipleChoice("What is your race?", new std::string[4]{ "Human","Dwarf","Elf","Halfling" }, 4))
		{
		case Player::Human:
			myLog.Write("Human Stats:");
			myPlayer.myRace = Player::Human;
			myPlayer.SetStats(true);
			DisplayStats(myPlayer,myLog, true);
			break;
		case Player::Dwarf:
			myLog.Write("Dwarf Stats:");
			myPlayer.myRace = Player::Dwarf;
			myPlayer.SetStats(true);
			DisplayStats(myPlayer, myLog, true);
			break;
		case Player::Elf:
			myLog.Write("Elf Stats");
			myPlayer.myRace = Player::Elf;
			myPlayer.SetStats(true);
			DisplayStats(myPlayer,myLog, true);
			break;
		case Player::Halfling:
			myLog.Write("Halfling Stats");
			myPlayer.myRace = Player::Halfling;
			myPlayer.SetStats(true);
			DisplayStats(myPlayer,myLog, true);
			break;
		}

		myLoop = YesNo(myLog);

	}

	myLoop = true;

	while (myLoop)
	{
		myPlayer.SetStats(true);
		switch (myLog.MultipleChoice("What is your class?", new std::string[3]{ "Warrior","Theif","Ranger" }, 3))
		{
		case 0:
			myLog.Write("Warrior stats");
			myPlayer.myClass = 0;
			myPlayer.SetStats(false);
			DisplayStats(myPlayer, myLog, true);
			break;
		case 1:
			myLog.Write("Theif stats");
			myPlayer.myClass = 1;
			myPlayer.SetStats(false);
			DisplayStats(myPlayer, myLog, true);
			break;
		case 2:
			myLog.Write("Ranger stats");
			myPlayer.myClass = 2;
			myPlayer.SetStats(false);
			DisplayStats(myPlayer, myLog, true);
			break;
		}

		myLoop = YesNo(myLog);
	}

	myLoop = true;

	while (myLoop)
	{
		Update(myPlayer, myLog);
	}
}

void Game::Update(Player& aPlayer, Log& aLog)
{
	system("CLS");
	switch (aLog.MultipleChoice("What will you do?", new std::string[7]{ "Travel", "Rest", "Level Up", "Character Sheet", "Shop", "Craft", "Quit" }, 7)) 
	{
	case 0:
		switch (aLog.MultipleChoice("Where will you go?", new std::string[4]{"Forwards","Left","Right","Back"},4))
		{
		case 0:

			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
		break;
	case 1:
		if (aPlayer.myHp < aPlayer.myMaxHp)
		{
			aPlayer.myHp += aPlayer.myMaxHp / 5;
			aLog.Write("You Regained" + std::to_string(aPlayer.myMaxHp / 5) + "HP!");
			if (aPlayer.myHp > aPlayer.myMaxHp)
			{
				aPlayer.myHp = aPlayer.myMaxHp;
			}
		}
		else if (aPlayer.myHp >= aPlayer.myMaxHp)
		{
			aLog.Write("You are already at max HP");
		}
		aLog.Write(std::to_string(aPlayer.myHp) + "/" + std::to_string(aPlayer.myMaxHp));
		system("pause");
		break;
	case 2:
		if (aPlayer.myXp >= (aPlayer.myLevel * 100)) {
			aPlayer.myXp -= (aPlayer.myLevel * 100);
			aPlayer.myLevel++;
			aLog.Write("You leveled up!\nNew level:" + std::to_string(aPlayer.myLevel));
			aLog.Write(std::to_string(aPlayer.myXp) + "/" + std::to_string(aPlayer.myLevel * 100) + "Xp\n");
			system("Pause");
			
		}
		else 
		{
			aLog.Write("Not Enough Xp ");
			aLog.Write(std::to_string(aPlayer.myXp) + "/" + std::to_string(aPlayer.myLevel*100) + "Xp");
			system("Pause");
		}
		break;
	case 3:
		DisplayStats(aPlayer,aLog, false);
		system("pause");
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		myLoop = false;
		break;

	}
	
	
}

void Game::DisplayStats(Player& aPlayer, Log& aLog, bool someOnlyStats)
{
	if (!someOnlyStats) 
	{
		std::cout << "HP:";
		aLog.Write(std::to_string(aPlayer.myMaxHp));
		std::cout << "Level:";
		aLog.Write(std::to_string(aPlayer.myLevel));
		std::cout << "Xp:";
		aLog.Write(std::to_string(aPlayer.myXp) + "/" + std::to_string(aPlayer.myLevel * 100) + "\n");

		for (int i = 0; i < sizeof(aPlayer.myItems);i ++)
		{
			aLog.Write(aPlayer.myItems[i].myName);
		}
	}
	std::cout << "Str:";
	aLog.Write(std::to_string(aPlayer.myStr));
	std::cout << "Speed:";
	aLog.Write(std::to_string(aPlayer.mySpeed));
	std::cout << "Luck:";
	aLog.Write(std::to_string(aPlayer.myLuck));
	std::cout << "Def:";
	aLog.Write(std::to_string(aPlayer.myDef));
	std::cout << "Acc:";
	aLog.Write(std::to_string(aPlayer.myAcc));
}

void Game::Fight(Player& aPlayer, Log& aLog)
{
	Enemy enemy(5);

	bool tempLoop = true;
	int tempFleeChance = 0;

	while (tempLoop)
	{
		switch (aLog.MultipleChoice("What Will You Do?", new std::string[4]{"Fight", "Block", "Use item", "Run away"}, 4))
		{
		case 0:
			enemy.myHp -= ((aPlayer.myItems[0].myPotency * (1+(aPlayer.myStr/10)))*(1-(enemy.myDef/100)));
			break;
		case 1:

			break;
		case 2:
			aPlayer.myItems[aLog.MultipleChoice("Which Item?", new std::string[5]{ aPlayer.myItems[0].myName, aPlayer.myItems[1].myName, aPlayer.myItems[2].myName, aPlayer.myItems[3].myName, aPlayer.myItems[4].myName }, 5)];
			break;
		case 3:
			tempFleeChance = rand() % 100 + 1;
			if (tempFleeChance <= (20 + aPlayer.mySpeed)) {
				tempLoop = false;
				aLog.Write("You successfully ran away.");
			}
			break;
		}
	}

	enemy.~Enemy();
}

bool Game::YesNo(Log& aLog) 
{
	std::string tempInput;
	aLog.Write("\nAre You Sure?(Y/N)");
	std::cin >> tempInput;

	if (tempInput == "Yes" || tempInput == "yes" || tempInput == "Y" || tempInput == "y")
	{
		system("CLS");
		return false;
	}
	else if (tempInput == "No" || tempInput == "no" || tempInput == "N" || tempInput == "n")
	{
		system("CLS");
		return true;
	}
}
