#pragma once

#include "Ennemy.h"
#include <vector>

class Room
{
public:
	Room(int posX, int posY, std::vector<Ennemy> ennemies, bool isThereABed, bool isThereAnExit);

	int getPosX();
	void setPosX(int posX);

	int getPosY();
	void setPosY(int posY);

	std::vector<Ennemy> getEnnemies();
	void setEnnemies(std::vector<Ennemy>);

	bool getBed();
	void setBed(bool isThereABed);

	bool getExit();
	void setExit(bool isThereAnExit);

	void PrintRoom();


protected:
	int posX;
	int posY;
	//std::vector<> objects;
	//std::vector<> hideObjects;
	std::vector<Ennemy> ennemies;
	bool isThereABed;
	bool isThereAnExit;
};

