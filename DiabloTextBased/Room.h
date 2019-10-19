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
		int myRoomType;

	private:
		float mySpawnRateEnemy, mySpawnRateLoot;

	

};
#endif
