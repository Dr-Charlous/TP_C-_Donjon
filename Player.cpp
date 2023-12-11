#include "Player.h"

Player::Player(std::string _name, int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor, int _exp, int _level) :
	Character(_name, _lifeMax, _life, _force, _weapon, _armor),
	exp(_exp),
	level(_level) {
}


int Player::getExp()
{
	return this->exp;
}

void Player::setExp(int exp)
{
	this->exp = exp;
}

int Player::getLevel()
{
	return this->level;
}

void Player::setLevel(int level)
{
	this->level = level;
}

void Player::Sleep(int sleepingHeal)
{
	this->life += sleepingHeal;
	if (this->life >= this->lifeMax) 
	{
		this->life = this->lifeMax;
	}
}

void Player::LevelUp(int *exp, int *level)
{
	if (*exp >= *level * 100) {
		*exp -= *level * 100;
		*level += 1;
	}
}
