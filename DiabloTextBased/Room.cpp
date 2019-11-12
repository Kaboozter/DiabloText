#include "Room.h"
#include <iostream>

Room::Room() 
{
	myRoomType = 0;
}

void Room::CreateRoom(int aType)
{
	myRoomType = aType;
	myRoomCleared = false;
}

Room::~Room()
{
}