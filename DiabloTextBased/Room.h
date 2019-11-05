#ifndef ROOM_HEADER
#define ROOM_HEADER

class Room
{

	public:
		enum RoomType
		{
			RoomTreasure,
			RoomArena,
			RoomSafeZone,
			RoomBoss,
		};
		int myRoomType, myNumEntrances;

		int* myConnectedRooms;

		Room(int aRoomType, int aNumEntrance);
		~Room();

	private:
		float mySpawnRateEnemy, mySpawnRateLoot;

	

};
#endif
