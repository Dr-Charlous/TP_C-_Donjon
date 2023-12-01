// TP_C++_Donjon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Character.h"
#include "Player.h"
#include "Ennemy.h"
#include "Room.h"

int main()
{
    Weapon sword("Great steel", 10);
    Weapon dager("Little man", 5);

    Armor cloth("Just cloths", 2);
    Armor steel("Steel armor", 25);

    Character chara("Character", 100, 100, 25, sword, steel);
    Player player("Adventurer", 100, 100, 25,sword, cloth, 0, 1);
    Ennemy ennemy("Goblin", 100, 100, 25, dager, cloth, 10);

    std::cout << chara.getName() << " : \n" << "- Life : " << chara.getLife() << " / " << chara.getLife() << "\n- Force : " << chara.getForce() << "\n- Equipement : \n - -Weapon : " << chara.getWeapon().getName() << "\n - -Armor : " << chara.getArmor().getName() << std::endl;
    std::cout << player.getName() << " : \n" << "- Life : " << player.getLife() << " / " << player.getLife() << "\n- Force : " << player.getForce() << "\n- Equipement : \n - -Weapon : " << player.getWeapon().getName() << "\n - -Armor : " << player.getArmor().getName() << "\n- Lvl : " << player.getLevel() << " / Exp : " << player.getExp() << std::endl;
    std::cout << ennemy.getName() << " : \n" << "- Life : " << ennemy.getLife() << " / " << ennemy.getLife() << "\n- Force : " << ennemy.getForce() << "\n- Equipement : \n - -Weapon : " << ennemy.getWeapon().getName() << "\n - -Armor : " << ennemy.getArmor().getName() << "\n- Exp : " << ennemy.getExp() << std::endl;

    std::vector<Potion> potionRoomstart;
    ennemiesRoomstart.push_back(ennemy);
    ennemiesRoomstart.push_back(ennemy);

    std::vector<Ennemy> ennemiesRoomstart;
    ennemiesRoomstart.push_back(ennemy);
    ennemiesRoomstart.push_back(ennemy);

    Room startingRoom(0, 0, potions, ennemiesRoomstart, false, false);

    std::cout << "\n" << std::endl;

    startingRoom.PrintRoom();
}