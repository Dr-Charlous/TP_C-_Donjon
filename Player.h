#pragma once

#include "Character.h"

class Player: public Character
{
public:
	Player(std::string _name, int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor, int _exp, int _level);

	int getExp();
	void setExp(int exp);

	int getLevel();
	void setLevel(int level);

	void LevelUp(int *exp,int *level);

protected:
	int exp;
	int level;
};

