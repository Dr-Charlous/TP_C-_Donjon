#include <iostream>
#include "Donjon.h"

Donjon::Donjon(std::vector<Room> _rooms, int _actualPosition, int _donjonLength) :
	rooms(_rooms),
	actualPosition(_actualPosition),
	donjonLength(_donjonLength)
{
}

std::vector<Room> Donjon::getRooms()
{
	return this->rooms;
}

void Donjon::setRoom(std::vector<Room> rooms)
{
	this->rooms = rooms;
}

int Donjon::getActualPosition()
{
	return this->actualPosition;
}

void Donjon::setActualPosition(int actualPosition)
{
	this->actualPosition = actualPosition;
}

int Donjon::getDonjonLength()
{
	return this->donjonLength;
}

void Donjon::setDonjonLength(int donjonLength)
{
	this->donjonLength = donjonLength;
}

void Donjon::PrintDonjon()
{
	std::cout << "Rooms : " << rooms.size() << ", Size : " << donjonLength << ", Player position : " << actualPosition << "\n" << std::endl;

	for (size_t i = 0; i < rooms.size(); i++)
	{
		std::cout << "Room " << i << " : " << std::endl;
		rooms[i].PrintRoom();
		std::cout << "\n" << std::endl;
	}
}
