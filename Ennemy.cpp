#include "Ennemy.h"

Ennemy::Ennemy(std::string _name, int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor, int _exp) :
	Character(_name, _lifeMax, _life, _force, _weapon, _armor),
	exp(_exp) {
}

int Ennemy::getExp()
{
	return this->exp;
}

void Ennemy::setExp(int exp)
{
	this->exp = exp;
}
