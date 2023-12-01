// TP_C++_Donjon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Ennemy.h"

int main()
{
    Character chara(100, 100, 25);
    Player player(100, 100, 25, 0, 1);
    Ennemy ennemy(100, 100, 25, 10);
    std::cout << "Character : \n" << "- Life : " << chara.getLife() << " / " << chara.getLife() << "\n- Force : " << chara.getForce() << std::endl;
    std::cout << "Player : \n" << "- Life : " << player.getLife() << " / " << player.getLife() << "\n- Force : " << player.getForce() << "\n- Lvl : " << player.getLevel() << " / Exp : " << player.getExp() << std::endl;
    std::cout << "Ennemy : \n" << "- Life : " << ennemy.getLife() << " / " << ennemy.getLife() << "\n- Force : " << ennemy.getForce() << "\n- Exp : " << ennemy.getExp() << std::endl;
}