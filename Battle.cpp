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

void Battle::fight()
{
    if (player->isAlive() && ennemy->isAlive()) {
        std::cout << player->getName() << " attack " << ennemy->getName() << std::endl;
        player->attack(*ennemy);
        std::cout << ennemy->getName() << " has " << ennemy->getLife() << " left" << std::endl;

        if (ennemy->isAlive()) {
            std::cout << ennemy->getName() << " attack " << player->getName() << std::endl;
            ennemy->attack(*player);
            std::cout << player->getName() << " has " << player->getLife() << " left" << std::endl;
        }
    }

    if (player->isAlive()) {
        std::cout << player->getName() << " wins!" << std::endl;
    }
    else {
        std::cout << ennemy->getName() << " wins!" << std::endl;
    }
}
