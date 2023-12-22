#include "Room.h"
#include <iostream>


Room::Room(std::string _name, std::vector<Potion*> _potion, std::vector<Ennemy*> _ennemies, bool _isThereABed, bool _isThereAnExit) :
	name(_name),
	potions(_potion),
	ennemies(_ennemies),
	isThereABed(_isThereABed),
	isThereAnExit(_isThereAnExit),
	rooms(rooms),
	hidenOnes(hidenOnes)
{
}

std::string Room::getName()
{
	return this->name;
}

void Room::setName(std::string name)
{
	this->name = name;
}

std::vector<Potion*> Room::getPotion()
{
	return this->potions;
}

void Room::setPotion(std::vector<Potion*> potions)
{
	this->potions = potions;
}

void Room::addPotion(Potion* potion)
{
	this->potions.push_back(potion);
}

std::vector<Ennemy*> Room::getEnnemies()
{
	return this->ennemies;
}

void Room::setEnnemies(std::vector<Ennemy*> ennemies)
{
	this->ennemies = ennemies;
}

void Room::setRooms(std::map<std::string, Room*> rooms)
{
	this->rooms = rooms;
}

void Room::addRooms(Room* rooms)
{
	this->rooms[rooms->getName()] = rooms;
}

std::map<std::string, Room*> Room::getRooms()
{
	return this->rooms;
}

bool Room::getBed()
{
	return this->isThereABed;
}

void Room::setBed(bool isThereABed)
{
	this->isThereABed = isThereABed;
}

bool Room::getExit()
{
	return this->isThereAnExit;
}

void Room::setExit(bool isThereAnExit)
{
	this->isThereAnExit;
}

std::vector<Potion*> Room::getHidenOnes()
{
	return this->hidenOnes;
}

void Room::setHidenOnes(std::vector<Potion*>)
{
	this->hidenOnes = hidenOnes;
}