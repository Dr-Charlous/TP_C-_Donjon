#include "Room.h"
#include <iostream>


Room::Room(std::vector<Potion> _potion, std::vector<Ennemy*> _ennemies, bool _isThereABed, bool _isThereAnExit) :
	potions(_potion),
	ennemies(_ennemies),
	isThereABed(_isThereABed),
	isThereAnExit(_isThereAnExit)
{
}

std::vector<Potion> Room::getPotion()
{
	return this->potions;
}

void Room::setPotion(std::vector<Potion> potions)
{
	this->potions = potions;
}

std::vector<Ennemy*> Room::getEnnemies()
{
	return this->ennemies;
}

void Room::setEnnemies(std::vector<Ennemy*> ennemies)
{
	this->ennemies = ennemies;
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

void Room::PrintRoom()
{
	for (int i = 0; i < potions.size(); i++)
	{
		std::cout << "\n   Objects : " << potions[i].getName() << std::endl;
	}
	for (int i = 0; i < ennemies.size(); i++)
	{
		std::cout << "\n   Ennemy : " << ennemies[i]->getName() << std::endl;
	}

	std::cout << "\n   Bed : " << isThereABed << " Exit : " << isThereAnExit << std::endl;
}

