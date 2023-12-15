#pragma once
#include <string>
#include "Player.h"

class Player;

class Potion
{
public:
	Potion(std::string name, int heal, int life, int force, bool used);

	std::string getName();
	void setName(std::string name);

	int getHeal();
	void setHeal(int heal);

	int getLife();
	void setLife(int life);

	int getForce();
	void setForce(int force);

	bool getUsed();
	void setUsed(bool used);

	void giveHeal(Player *player);
	void giveLife(Player *player);
	void giveForce(Player *player);

protected:
	std::string name;
	int heal;
	int life;
	int force;
	bool used;
};

