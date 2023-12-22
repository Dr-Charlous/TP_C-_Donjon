#include "Player.h"
#include "Ennemy.h"
#include <vector>
#include "Potion.h"
#include <ctime>
#include <iostream>

Player::Player(std::string _name, int _lifeMax, int _life, int _force,  int _exp, int _level) :
	Character(_name, _lifeMax, _life, _force),
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

std::vector<Potion*> Player::getPotionHeal()
{
	return this->potionInHand;
}

void Player::setPotionHeal(std::vector<Potion*> potionInHand)
{
	this->potionInHand = potionInHand;
}

void Player::addPotionHeal(Potion* potionInHand)
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

void Player::LevelUp()
{
	if (this->getExp() >= level * 100) {
		this->setExp(this->getExp() - (this->getLevel() * 100));
		this->setLevel(this->getLevel() + 1);

		this->setLifeMax(this->getLifeMax() + this->getLevel());
		this->setLife(this->getLife() + this->getLevel());
		this->setForce(this->getForce() + this->getLevel());
		std::cout << "You win 1 level ! " << this->getLevel() << " points in lifeMax and " << this->getLevel() << " points in force !" << std::endl;
	} 
}
