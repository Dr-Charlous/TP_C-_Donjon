#include "Room.h"
#include <iostream>

Room::Room(int _posX, int _posY, std::vector<Ennemy> _ennemies, bool _isThereABed, bool _isThereAnExit) :
	posX(_posX),
	posY(_posY),
	ennemies(_ennemies),
	isThereABed(_isThereABed),
	isThereAnExit(_isThereAnExit)
{
}

int Room::getPosX()
{
	return this->posX;
}

void Room::setPosX(int posX)
{
	this->posX = posX;
}

int Room::getPosY()
{
	return this->posY;
}

void Room::setPosY(int posY)
{
	this->posY = posY;
}

std::vector<Ennemy> Room::getEnnemies()
{
	return this->ennemies;
}

void Room::setEnnemies(std::vector<Ennemy> ennemies)
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
	for (size_t i = 0; i < ennemies.size(); i++)
	{
		std::cout << "Pos x :" << posX << " Pos y :" << posY << "\n   Ennemy : " << ennemies[i].getName() << "\n     Bed : " << isThereABed << " Exit : " << isThereAnExit << std::endl;
	}
}

