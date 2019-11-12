#include <iostream>
#include <vector>
#include "Game.h"
#include "item.h"
#include "Enemy.h"
#include "Player.h"
#include "Log.h"
#include "Room.h"

std::string myInput;

bool myLoop = true;

void Game::Initialize()
{
	Player myPlayer;
	Log myLog;
	Weapons myWeapon(0, rand() % 3, "Starter");
	myCurrRoom = 0, myCurrStage = 1;
	myRooms = new Room[35];

	//myWeapon.CalWeaponPot(myWeapon.myQuality, myWeapon.myType);

	myPlayer.myInventory[0] = myWeapon;

	for (int i = 0; i < 7; i++)
	{
		myPlayer.myMaterialInventory[i].myType = i;
	}
	myRooms[0].CreateRoom(0);
	for (int i = 1; i < 35; i++)
	{
		myRooms[i].CreateRoom(2);
        #pragma region SafeZone & Bossroom
		if (i == 3) {
			myRooms[i].CreateRoom(0);
		}
		if (i == 5) {
			myRooms[i].CreateRoom(0);
		}
		if (i == 8) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 10) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 13) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 15) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 18) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 20) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 23) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 25) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 28) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 30) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 33) {
			myRooms[i].CreateRoom(0);

		}
		if (i == 4) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 9) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 14) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 19) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 24) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 29) {
			myRooms[i].CreateRoom(3);
		}
		if (i == 34) {
			myRooms[i].CreateRoom(3);
		}
#pragma endregion
	}

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

	aLog.Write(std::to_string(myCurrRoom));
	switch (myRooms[myCurrRoom].myRoomType)
	{
	case 0:
		aLog.Write("You feel safe");
		if (myRooms[(myCurrRoom+1)].myRoomType == 3) {
			aLog.Write("In The Next Room Is A Floor Guardian, Don't Let Your Guard Down!");
		}
		break;
	case 1:

		break;
	case 2:
		if (!myRooms[myCurrRoom].myRoomCleared) {
			Fight(aPlayer, aLog, false);
		}
		break;
	case 3:
		if (!myRooms[myCurrRoom].myRoomCleared) {
			Fight(aPlayer, aLog, true);
		}
		break;
	}
	aLog.Write(std::to_string(myCurrRoom));

	switch (aLog.MultipleChoice("What will you do?", new std::string[7]{ "Continue", "Rest", "Level Up", "Character Sheet", "Shop", "Craft", "Quit" }, 7)) 
	{
	case 0:
		switch (aLog.MultipleChoice("Where will you go?", new std::string[2]{"Onward","Back"},2))
		{
		case 0:
			if (myRooms[myCurrRoom].myRoomType != 3) {
				myRooms[myCurrRoom].myRoomCleared = false;
			}
			myCurrRoom++;
			break;
		case 1:
			if (myRooms[myCurrRoom].myRoomType != 3) {
				myRooms[myCurrRoom].myRoomCleared = false;
			}
			if (myCurrRoom < (myCurrStage * 5)) {
				myCurrRoom--;
			}
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
		if (myRooms[myCurrRoom].myRoomType == 0) {
			//switch (aLog.MultipleChoice("What do you wish to buy?", new std::string[]))
			//{
			//default:
			//	break;
			//}
		}
		break;
	case 5:
		
		if (myRooms[myCurrRoom].myRoomType == 0) {
			switch (aLog.MultipleChoice("What Material do you wish to use?", new std::string[7]{"Goblin Tooth" + aPlayer.myMaterialInventory[0].myAmount,
				"Wolf Pelt" + aPlayer.myMaterialInventory[1].myAmount, 
				"Ogre bones" + aPlayer.myMaterialInventory[2].myAmount,
				"Giant head" + aPlayer.myMaterialInventory[3].myAmount,
				"Dragonscales" + aPlayer.myMaterialInventory[4].myAmount,
				"Divine Spark" + aPlayer.myMaterialInventory[5].myAmount,
				"Draconic core" + aPlayer.myMaterialInventory[6].myAmount },7))
			{
			case 0:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {
					switch (aLog.MultipleChoice("Which Weapon do you want to craft?", new std::string[2]{aPlayer.myMaterialInventory[0].myResultName1 + "(Full Atk, extra attributes /1.5)", aPlayer.myMaterialInventory[0].myResultName2 + "(Full Attributes, Atk /1.5)" },2))
					{
					case 0:
						
						break;
					case 1:
						break;
					}
				}
				break;
			case 1:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			case 2:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			case 3:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			case 4:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			case 5:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			case 6:
				if (aPlayer.myMaterialInventory[0].myAmount > 0) {

				}
				break;
			}
		}
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

		for (int i = 0; i < sizeof(aPlayer.myInventory);i ++)
		{
			aLog.Write(aPlayer.myInventory[i].myName);
			aLog.Write(std::to_string(aPlayer.myInventory[i].myPotency));

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

void Game::Fight(Player& aPlayer, Log& aLog, bool aBoss)
{
	Enemy enemy(myCurrStage, aBoss);

	bool tempLoop = true;
	int tempFleeChance = 0;
	float tempOriginalPlayerDef = aPlayer.myDef, tempOriginalEnemyDef = enemy.myDef;


	while (tempLoop)
	{
		system("CLS");
		aPlayer.myDef = tempOriginalPlayerDef;
		aLog.Write(enemy.myAttackPhrase);
		switch (aLog.MultipleChoice("What Will You Do?", new std::string[5]{"Attack", "Block", "Use Potion", "Run away", "*Admin Kill*"}, 5))
		{
		case 0:
			enemy.myHp -= ((aPlayer.myInventory[0].myPotency * (1+(aPlayer.myStr/10)))*(1-(enemy.myDef/100)));
			aLog.Write(std::to_string(enemy.myHp));
			system("pause");
			break;
		case 1:
			aPlayer.myDef = aPlayer.myDef * 1.5f;
			system("pause");
			break;
		case 2:
			aPlayer.myPotion.UseItem(aPlayer);
			system("pause");
			break;
		case 3:
			tempFleeChance = rand() % 100 + 1;
			aLog.Write(std::to_string(tempFleeChance));
			if (tempFleeChance <= (109 + aPlayer.mySpeed)) {
				tempLoop = false;
				for (int i = myCurrRoom; i > 0; i--)
				{
					if (myRooms[i].myRoomType == 0) {
						myCurrRoom = i;
						break;
					}
				}
				aLog.Write("You successfully ran away.");
			}
			system("pause");
			break;
		case 4:
			enemy.myHp = 0;
			break;
		}
		if (enemy.myHp <= 0) {
			tempLoop = false;
			if (enemy.myIsBoss == true) {
				myCurrStage++;
			}
			aPlayer.myXp += enemy.myXpGive;
			myRooms[myCurrRoom].myRoomCleared = true;
		}
		enemy.myDef = tempOriginalEnemyDef;
		enemy.EnemyTurn(aPlayer,aLog);

	}
	system("cls");
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
