#include "Character.h"

Character::Character(std::string _name, int _lifeMax, int _life, int _force) :
	name(_name),
	lifeMax(_lifeMax),
	life(_life),
	force(_force),
	weapon(Weapon("Hands", 0)),
	armor(Armor("Naked", 0)) {
}

std::string Character::getName()
{
	return this->name;
}

void Character::setName(std::string name)
{
	this->name = name;
}

int Character::getLifeMax()
{
	return this->lifeMax;
}

void Character::setLifeMax(int lifeMax)
{
	this->lifeMax = lifeMax;
}

int Character::getLife()
{
	return this->life;
}

void Character::setLife(int life)
{
	this->life = life;
}

int Character::getForce()
{
	return this->force;
}

void Character::setForce(int force)
{
	this->force = force;
}

Weapon Character::getWeapon()
{
	return this->weapon;
}

void Character::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

Armor Character::getArmor()
{
	return this->armor;
}

void Character::setArmor(Armor armor)
{
	this->armor = armor;
}
