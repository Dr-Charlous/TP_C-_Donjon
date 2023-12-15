#include "Potion.h"

Potion::Potion(std::string _name, int _heal, int _life, int _force) :
	name(_name),
	heal(_heal),
	life(_life),
	force(_force),
	used(false)
{
}

std::string Potion::getName()
{
	return this->name;
}

void Potion::setName(std::string name)
{
	this->name = name;
}

int Potion::getHeal()
{
	return this->heal;
}

void Potion::setHeal(int heal)
{
	this->heal = heal;
}

int Potion::getLife()
{
	return this->life;
}

void Potion::setLife(int life)
{
	this->life = life;
}

int Potion::getForce()
{
	return this->force;
}

void Potion::setForce(int force)
{
	this->force = force;
}

bool Potion::getUsed()
{
	return this->used;
}

void Potion::setUsed(bool used)
{
	this->used = used;
}

void Potion::giveLife(Player* player)
{
	if (this->getLife() > 0) {
		player->setLifeMax(player->getLifeMax() + this->life);
	}
}

void Potion::giveForce(Player* player)
{
	if (this->getForce() > 0) {
		player->setForce(player->getForce() + this->life);
	}
}

void Potion::giveHeal(Player* player)
{
	if (this->getHeal() > 0) {
		player->setLife(player->getLife() + this->life);
		if (player->getLife() > player->getLifeMax())
			player->setLife(player->getLifeMax());
	}
}
