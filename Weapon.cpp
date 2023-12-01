#include "Weapon.h"

Weapon::Weapon(std::string _name, int _damage) :
	name(_name),
	damage(_damage) {
}

std::string Weapon::getName()
{
	return this->name;
}

void Weapon::setName(std::string name)
{
	this->name = name;
}

int Weapon::getDamage()
{
	return this->damage;
}

void Weapon::setDamage(int damage)
{
	this->damage = damage;
}
