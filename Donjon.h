#pragma once
#include "Room.h"

class Donjon
{
public:
	Donjon(Room* _actualRoom);

	std::map<std::string, Room*> getRooms();
	void setRooms(std::map<std::string, Room*>);

	Room* getActualRoom();
	void setActualRoom(Room*);

protected:
	std::map<std::string, Room*> rooms;
	Room* actualRoom;
};

