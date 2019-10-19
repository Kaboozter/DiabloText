// DiabloTextBased.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Room.h"
#include "Player.h"
#include "item.h";
#include "Game.h";

#define Log(message) std::cout << message << std::endl;

struct MyStruct
{

};

Room room[10];

int main()
{

	Game* tempGame = new Game();
	tempGame->Initialize();
}
