#include "Battle.h"
#include <iostream>

Battle::Battle(Player _player, Ennemy _ennemy) :
	player(&_player),
	ennemy(&_ennemy)
{
}

Player* Battle::getPlayer()
{
	return this->player;
}

void Battle::setPlayer(Player* player)
{
	this->player = player;
}

Ennemy* Battle::getEnnemy()
{
	return this->ennemy;
}

void Battle::setEnnemy(Ennemy* ennemy)
{
	this->ennemy = ennemy;
}

bool Battle::fight(Player& player, Ennemy& ennemy)
{
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    if (player.isAlive() && ennemy.isAlive()) {
        std::cout << player.getName() << " attack " << ennemy.getName() << std::endl;
        player.attack(ennemy);
        std::cout << ennemy.getName() << " has take " << ennemy.getLifeMax() - ennemy.getLife() << " damages\n" << std::endl;

        ennemyAttack(player, ennemy);
    }

    if (!ennemy.isAlive()) {
        std::cout << player.getName() << " wins!" << std::endl;
        return false;
    }
    else if (!player.isAlive()) {
        std::cout << ennemy.getName() << " wins!" << std::endl;
        return false;
    }
    else {
        std::cout << "The battle is not finished !" << std::endl;
        return true;
    }
}

bool Battle::ennemyAttack(Player& player, Ennemy& ennemy) {
    if (ennemy.isAlive()) {
        std::cout << ennemy.getName() << " attack " << player.getName() << std::endl;
        ennemy.attack(player);
        std::cout << player.getName() << " has take " << player.getLifeMax() - player.getLife() << " damages" << std::endl;
    }

    std::cout << "\n" << std::endl;
    std::cout << player.getName() << " | Levels : " << player.getLevel() << " | Exp : " << player.getExp() << " | Life : " << player.getLife() << " / " << player.getLifeMax() << " | Force : " << player.getForce() << " | " << player.getArmor().getName() << "(" << player.getArmor().getDefence() << ")" << " | " << player.getWeapon().getName() << "(" << player.getWeapon().getDamage() << ")" << std::endl;
    std::cout << ennemy.getName() << " | Life : " << ennemy.getLife() << " / " << ennemy.getLifeMax() << " | Force : " << ennemy.getForce() << " | " << ennemy.getArmor().getName() << "(" << ennemy.getArmor().getDefence() << ")" << " | " << ennemy.getWeapon().getName() << "(" << ennemy.getWeapon().getDamage() << ")" << std::endl;
    std::cout << "\n" << std::endl;

    if (!ennemy.isAlive()) {
        std::cout << player.getName() << " wins!" << std::endl;
        return false;
    }
    else if (!player.isAlive()) {
        std::cout << ennemy.getName() << " wins!" << std::endl;
        return false;
    }
    else {
        std::cout << "The battle is not finished !" << std::endl;
        return true;
    }
}
