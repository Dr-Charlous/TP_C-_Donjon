#include "Player.h"

Player::Player(int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor, int _exp, int _level) :
	Character(_lifeMax, _life, _force, _weapon, _armor),
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