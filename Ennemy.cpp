#include "Ennemy.h"

Ennemy::Ennemy(int _lifeMax, int _life, int _force, int _exp) :
	Character(_lifeMax, _life, _force),
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
