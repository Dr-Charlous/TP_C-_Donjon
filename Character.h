#pragma once
#include "Weapon.h"
#include "Armor.h"
class Character
{
public:
	Character(std::string name, int _lifeMax, int _life, int _force);

	std::string getName();
	void setName(std::string _name);

	int getLifeMax();
    void setLifeMax(int lifeMax);

	int getLife();
	void setLife(int life);

	int getForce();
	void setForce(int force);

	Weapon getWeapon();
	void setWeapon(Weapon weapon);

	Armor getArmor();
	void setArmor(Armor armor);

protected :
	std::string name;
	int lifeMax;
	int life;
	int force;
	//var inventory;
	Weapon weapon;
	Armor armor;
};