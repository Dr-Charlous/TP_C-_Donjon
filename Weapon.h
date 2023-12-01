#pragma once
#include <string>
class Weapon
{
public:
	Weapon(std::string name,int damage);

	std::string getName();
	void setName(std::string name);

	int getDamage();
	void setDamage(int lifeMax);

protected:
	std::string name;
	int damage;
};

