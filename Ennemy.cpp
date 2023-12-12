#include "Ennemy.h"
#include "Player.h"

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

void Ennemy::attack(Player& target)
{
	target.recieveDamage(this->force + this->getWeapon().getDamage());
}

void Ennemy::recieveDamage(int damage)
{
	int actualDamage = (damage - armor.getDefence()) * ((rand() % 10) + 1);
	if (actualDamage < 0) actualDamage = 0;
	life -= actualDamage;
}

bool Ennemy::isAlive()
{
	return life > 0;
}
