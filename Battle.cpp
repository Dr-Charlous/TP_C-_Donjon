#include "Battle.h"
#include <iostream>

Battle::Battle(Player* _player, Ennemy* _ennemy) :
	player(_player),
	ennemy(_ennemy)
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

bool Battle::fight(Player* player, Ennemy* ennemy)
{
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    if (player->isAlive() && ennemy->isAlive()) {
        int lifeBefore = ennemy->getLife();
        std::cout << player->getName() << " attack " << ennemy->getName() << std::endl;
        player->attack(ennemy);
        std::cout << ennemy->getName() << " has take " << lifeBefore - ennemy->getLife() << " damages\n" << std::endl;

        return ennemyAttack(player, ennemy);
    }
}

bool Battle::ennemyAttack(Player* player, Ennemy* ennemy) {
    if (ennemy->isAlive()) {
        int lifeBefore = player->getLife();
        std::cout << ennemy->getName() << " attack " << player->getName() << std::endl;
        ennemy->attack(player);
        std::cout << player->getName() << " has take " << lifeBefore - player->getLife() << " damages" << std::endl;
    }

    std::cout << "\n" << std::endl;
    std::cout << player->getName() << " | Levels : " << player->getLevel() << " | Exp : " << player->getExp() << " | Life : " << player->getLife() << " / " << player->getLifeMax() << " | Force : " << player->getForce() << " | " << player->getArmor().getName() << "(" << player->getArmor().getDefence() << ")" << " | " << player->getWeapon().getName() << "(" << player->getWeapon().getDamage() << ")" << std::endl;
    std::cout << ennemy->getName() << " | Life : " << ennemy->getLife() << " / " << ennemy->getLifeMax() << " | Force : " << ennemy->getForce() << " | " << ennemy->getArmor().getName() << "(" << ennemy->getArmor().getDefence() << ")" << " | " << ennemy->getWeapon().getName() << "(" << ennemy->getWeapon().getDamage() << ")" << std::endl;
    std::cout << "\n" << std::endl;

    if (!ennemy->isAlive()) {
        std::cout << player->getName() << " wins!" << std::endl;
        std::cout << player->getName() << " gain " << player->getExp() << " exp !" << std::endl;

        player->setExp(player->getExp() + ennemy->getExp());
        player->LevelUp();

        if (ennemy->getWeapon().getDamage() != 0) {
            std::cout << "Your ennemi drop : " << ennemy->getWeapon().getName() << "(" << ennemy->getWeapon().getDamage() << ") and your's is " << player->getWeapon().getName() << "(" << player->getWeapon().getDamage() << ")" << "\nDo you want to equip it or abandon it ?\n1 : equip it\n2 : abandon it" << std::endl;
            int choice = 0;
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "You choose to esuip it" << std::endl;
                player->setWeapon(ennemy->getWeapon());
            }
            else {
                std::cout << "You choose to abandon it\n" << std::endl;
            }
        }

        if (ennemy->getArmor().getDefence() != 0) {
            std::cout << "Your ennemi drop : " << ennemy->getArmor().getName() << "(" << ennemy->getArmor().getDefence() << ") and your's is " << player->getArmor().getName() << "(" << player->getArmor().getDefence() << ")" << "\nDo you want to equip it or abandon it ?\n1 : equip it\n2 : abandon it" << std::endl;
            int choice = 0;
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "You choose to esuip it" << std::endl;
                player->setArmor(ennemy->getArmor());
            }
            else {
                std::cout << "You choose to abandon it\n" << std::endl;
            }
        }

        return false;
    }
    else if (!player->isAlive()) {
        std::cout << ennemy->getName() << " wins!" << std::endl;
        std::cout << "\nYou lose... try again !" << std::endl;
        return false;
    }
    else {
        std::cout << "The battle is not finished !" << std::endl;
        return true;
    }
}
