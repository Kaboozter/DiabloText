#include "Room.h"

Room::Room(int aRoomType, int aNumEntrance) 
{
	myRoomType = aRoomType;
	myNumEntrances = aNumEntrance;
	

	myConnectedRooms = new int[myNumEntrances];
}