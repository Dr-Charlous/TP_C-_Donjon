#pragma once

#include "Character.h"
#include "Player.h"

class Player;

class Ennemy : public Character
{
public:
	Ennemy(std::string _name, int _lifeMax, int _life, int _force, int _exp);

	int getExp();
	void setExp(int exp);

	void attack(Player* target);
	void recieveDamage(int damage);
	bool isAlive();

protected:
	int exp;
};

