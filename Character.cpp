#include "Character.h"

Character::Character(int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor) :
	lifeMax(_lifeMax),
	life(_life),
	force(_force),
	weapon(_weapon),
	armor(_armor) {
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
