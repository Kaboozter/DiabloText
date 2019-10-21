#ifndef ROOM_HEADER
#define ROOM_HEADER

class Room
{

	public:
		enum RoomType
		{
			TreasureRoom,
			Arena,
			SafeZone,
			BossRoom,
		};
		int myRoomType, myNumEntrances;

	private:
		float mySpawnRateEnemy, mySpawnRateLoot;

	

};
#endif
