#include <iostream>
#include "Donjon.h"

Donjon::Donjon(Room* _actualRoom) :
	rooms(rooms),
	actualRoom(_actualRoom)
{
}

std::map<std::string, Room*> Donjon::getRooms()
{
	return this->rooms;
}

void Donjon::setRooms(std::map<std::string, Room*> rooms)
{
	this->rooms = rooms;
}

Room* Donjon::getActualRoom()
{
	return this->actualRoom;
}

void Donjon::setActualRoom(Room* actualRoom)
{
	this->actualRoom = actualRoom;
}
