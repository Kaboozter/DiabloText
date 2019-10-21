#include <iostream>
#include <conio.h>
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "item.h";
#include "Log.h";

std::string myInput;
Player::Race hash(std::string aInString)
{
	if (aInString == "Human" || aInString == "human") return Player::Human;
	else if (aInString == "Dwarf" || aInString == "dwarf") return Player::Dwarf;
	else if (aInString == "Elf" || aInString == "elf") return Player::Elf;
	else if (aInString == "Halfling" || aInString == "halfling") return Player::Halfling;
}

bool myLoop = true;

void Game::Initialize()
{
	Player player;
	Log log;

	while (myLoop)
	{
		switch (log.MultipleChoice("What is your race?", new std::string[4]{ "Human","Dwarf","Elf","Halfling" }, 4))
		{
		case Player::Human:
			log.Write("Human Stats:");
			player.myRace = Player::Human;
			player.SetStats(true);
			DisplayStats(player,log, true);
			break;
		case Player::Dwarf:
			log.Write("Dwarf Stats:");
			player.myRace = Player::Dwarf;
			player.SetStats(true);
			DisplayStats(player, log, true);
			break;
		case Player::Elf:
			log.Write("Elf Stats");
			player.myRace = Player::Elf;
			player.SetStats(true);
			DisplayStats(player,log, true);
			break;
		case Player::Halfling:
			log.Write("Halfling Stats");
			player.myRace = Player::Halfling;
			player.SetStats(true);
			DisplayStats(player,log, true);
			break;
		}

		myLoop = YesNo(log);

	}

	myLoop = true;

	while (myLoop)
	{
		player.SetStats(true);
		switch (log.MultipleChoice("What is your class?", new std::string[3]{ "Warrior","Theif","Ranger" }, 3))
		{
		case 0:
			log.Write("Warrior stats");
			player.myClass = 0;
			player.SetStats(false);
			DisplayStats(player, log, true);
			break;
		case 1:
			log.Write("Theif stats");
			player.myClass = 1;
			player.SetStats(false);
			DisplayStats(player, log, true);
			break;
		case 2:
			log.Write("Ranger stats");
			player.myClass = 2;
			player.SetStats(false);
			DisplayStats(player, log, true);
			break;
		}

		myLoop = YesNo(log);
	}

	myLoop = true;

	while (myLoop)
	{
		Update(player, log);
	}
}

void Game::Update(Player& aPlayer, Log aLog)
{
	system("CLS");
	switch (aLog.MultipleChoice("What will you do?", new std::string[7]{ "Travel", "Rest", "Level Up", "Character Sheet", "Shop", "Craft", "Quit" }, 6)) 
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
		aPlayer.myHp += aPlayer.myMaxHp / 5;
		aLog.Write("You Regained" + std::to_string(aPlayer.myMaxHp / 5) + "HP!");
		aLog.Write(std::to_string(aPlayer.myHp) + "/" + std::to_string(aPlayer.myMaxHp));
		system("pause");
		break;
	case 2:
		if (aPlayer.myXp >= (aPlayer.myLevel*100)) {
			aPlayer.myXp -= (aPlayer.myLevel * 100);
			aPlayer.myLevel++;
			aLog.Write("You leveled up!\nNew level:" + std::to_string(aPlayer.myLevel));
			aLog.Write(std::to_string(aPlayer.myXp) + "/" + std::to_string(aPlayer.myLevel * 100) + "Xp\n");
			system("Pause");
			
		}
		else 
		{
			aLog.Write("Not Enough Xp");
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

void Game::DisplayStats(Player& aPlayer, Log aLog, bool someOnlyStats)
{
	if (!someOnlyStats) 
	{
		std::cout << "HP:";
		aLog.Write(std::to_string(aPlayer.myMaxHp));
		std::cout << "Level:";
		aLog.Write(std::to_string(aPlayer.myLevel));
		std::cout << "Xp:";
		aLog.Write(std::to_string(aPlayer.myXp) + "/" + std::to_string(aPlayer.myLevel * 100) + "\n");
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

bool Game::YesNo(Log aLog) 
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
