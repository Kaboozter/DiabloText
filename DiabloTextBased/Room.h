#ifndef ROOM_HEADER
#define ROOM_HEADER

class Room
{

	public:
		enum RoomType
		{
			RoomSafeZone,
			RoomTreasure,
			RoomArena,
			RoomBoss,
		};
		int myRoomType, myNumEntrances;

		int* myConnectedRooms;

		Room();
		~Room();
		
		void CreateRoom(int aType, int aNumEntrance);

	private:
		float mySpawnRateEnemy, mySpawnRateLoot;

	

};
#endif
