#pragma once

#include "Ennemy.h"
#include "Potion.h"
#include "Room.h"
#include <map>

class Room
{
public:
	Room(std::string name, std::vector<Potion*> potion, std::vector<Ennemy*> ennemies, bool isThereABed, bool isThereAnExit);

	std::string getName();
	void setName(std::string);

	std::vector<Potion*> getPotion();
	void setPotion(std::vector<Potion*>);
	void addPotion(Potion*);

	std::vector<Ennemy*> getEnnemies();
	void setEnnemies(std::vector<Ennemy*>);
	
	std::map<std::string, Room*> getRooms();
	void setRooms(std::map<std::string, Room*>);
	void addRooms(Room*);

	bool getBed();
	void setBed(bool isThereABed);

	bool getExit();
	void setExit(bool isThereAnExit);

	std::vector<Potion*> getHidenOnes();
	void setHidenOnes(std::vector<Potion*>);

protected:
	std::string name;
	std::vector<Potion*> potions;
	//std::vector<> hideObjects;
	std::vector<Ennemy*> ennemies;
	std::map<std::string, Room*> rooms;
	bool isThereABed;
	bool isThereAnExit;
	std::vector<Potion*> hidenOnes;
};

