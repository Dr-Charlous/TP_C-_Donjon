#pragma once

#include "Character.h"

class Player: public Character
{
public:
	Player(int _lifeMax, int _life, int _force, int _exp, int _level);

	int getExp();
	void setExp(int exp);

	int getLevel();
	void setLevel(int level);

protected:
	int exp;
	int level;
};

