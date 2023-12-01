#include "Character.h"

Character::Character(int _lifeMax, int _life, int _force) :
	lifeMax(_lifeMax),
	life(_life),
	force(_force) {
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
