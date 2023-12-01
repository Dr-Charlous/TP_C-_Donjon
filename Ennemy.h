#pragma once

#include "Character.h"

class Ennemy : public Character
{
public:
	Ennemy(std::string _name, int _lifeMax, int _life, int _force, Weapon weapon, Armor armor, int _exp);

	int getExp();
	void setExp(int exp);

protected:
	int exp;
};

