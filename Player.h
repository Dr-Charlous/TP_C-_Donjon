#pragma once

#include "Character.h"
#include <vector>
#include "Ennemy.h"
#include "Potion.h"

class Player;
class Ennemy;
class Potion;

class Player: public Character
{
public:
	Player(std::string _name, int _lifeMax, int _life, int _force, Weapon _weapon, Armor _armor, int _exp, int _level);

	int getExp();
	void setExp(int exp);

	int getLevel();
	void setLevel(int level);

	void LevelUp(int *exp,int *level);
	void Sleep(int sleepingHeal);

	std::vector<Potion> getPotionHeal();
	void setPotionHeal(std::vector<Potion> potionInHand);
	void addPotionHeal(Potion potionInHand);

	void attack(Ennemy* target);
	void recieveDamage(int damage);
	bool isAlive();

protected:
	int exp;
	int level;
	std::vector<Potion> potionInHand;
};

