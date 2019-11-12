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
		int myRoomType;
		bool myRoomCleared;

		Room();
		~Room();
		
		void CreateRoom(int aType);

	private:
		float mySpawnRateEnemy, mySpawnRateLoot;

	

};
#endif
