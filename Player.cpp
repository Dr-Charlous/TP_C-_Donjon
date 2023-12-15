#include "Player.h"
#include "Ennemy.h"
#include <vector>
#include "Potion.h"
#include <ctime>

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

std::vector<Potion> Player::getPotionHeal()
{
	return this->potionInHand;
}

void Player::setPotionHeal(std::vector<Potion> potionInHand)
{
	this->potionInHand = potionInHand;
}

void Player::addPotionHeal(Potion potionInHand)
{
	this->potionInHand.push_back(potionInHand);
}

void Player::attack(Ennemy* target)
{
	target->recieveDamage(this->force + this->getWeapon().getDamage());
}

void Player::recieveDamage(int damage)
{
	std::srand(std::time(nullptr));
	int actualDamage = (damage - armor.getDefence()) + (damage - armor.getDefence() / 100 * (rand() % 10) + 1);
	if (actualDamage < 0) actualDamage = 0;
	life -= actualDamage;
}

bool Player::isAlive()
{
	return life > 0;
}

void Player::LevelUp(int* exp, int* level)
{
	if (*exp >= *level * 100) {
		*exp -= *level * 100;
		*level += 1;
	}
}
