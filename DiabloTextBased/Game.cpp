#include "Game.h"
#include <iostream>
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
	while (myLoop)
	{
		Player player;
		Log log;

		switch (log.MultipleChoice("What is your race?", new std::string[4]{ "Human","Dwarf","Elf","Halfling" }, 4))
		{
		case Player::Human:
			log.Write("Human Stats:");
			player.myRace = Player::Human;
			player.SetStats();
			DisplayStats(player,log);
			break;
		case Player::Dwarf:
			log.Write("Dwarf Stats:");
			player.myRace = Player::Dwarf;
			player.SetStats();
			DisplayStats(player, log);
			break;
		case Player::Elf:
			log.Write("Elf Stats");
			player.myRace = Player::Elf;
			player.SetStats();
			DisplayStats(player,log);
			break;
		case Player::Halfling:
			log.Write("Halfling Stats");
			player.myRace = Player::Halfling;
			player.SetStats();
			DisplayStats(player,log);
			break;
		}
		log.Write("");
		log.Write("Are You Sure?");
		std::cin >> myInput;

		if (myInput == "Yes")
		{
			system("CLS");
			myLoop = false;
		}
		else if (myInput == "No")
		{
			system("CLS");
		}


	}
}

void Game::Update()
{

}

void Game::DisplayStats(Player aPlayer, Log aLog)
{
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
