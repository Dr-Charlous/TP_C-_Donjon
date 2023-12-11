#pragma once
#include <vector>
#include "Room.h"

class Donjon
{
public:
	Donjon(std::vector<Room> _rooms, int _actualPosition, int _donjonLength);

	std::vector<Room> getRooms();
	void setRoom(std::vector<Room>);

	int getActualPosition();
	void setActualPosition(int);

	int getDonjonLength();
	void setDonjonLength(int);

	void PrintDonjon();


protected:
	std::vector<Room> rooms;
	int actualPosition;
	int donjonLength;
};

