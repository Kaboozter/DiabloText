#include "Room.h"

Room::Room() 
{
	myRoomType = 0;
	myNumEntrances = 0;
}

void Room::CreateRoom(int aType, int aNumEntrance)
{
	myRoomType = aType;
	myNumEntrances = aNumEntrance;
	myConnectedRooms = new int[myNumEntrances];
}

Room::~Room()
{
	delete[](myConnectedRooms);
}