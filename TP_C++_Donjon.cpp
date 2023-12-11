// TP_C++_Donjon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Ennemy.h"
#include "Room.h"
#include "Donjon.h"

void Initialize()
{
	//Weapons
	Weapon sword("Great steel", 10);
	Weapon dager("Little man", 5);

	//Armors
	Armor cloth("Just cloths", 2);
	Armor steel("Steel armor", 25);

	//Potions
	Potion potion("Heal potion", 10, 0, 0);

	//Characters
	Character chara("Character", 100, 100, 25, sword, steel);
	Player player("Adventurer", 100, 100, 25, sword, cloth, 0, 1);
	Ennemy ennemy("Goblin", 100, 100, 25, dager, cloth, 10);

	//Potions in room
	std::vector<Potion> potionRoomstart;
	potionRoomstart.push_back(potion);
	potionRoomstart.push_back(potion);

	//Ennemies in room
	std::vector<Ennemy> ennemiesRoomstart;
	ennemiesRoomstart.push_back(ennemy);
	ennemiesRoomstart.push_back(ennemy);

	//Room
	Room startingRoom(0, 0, potionRoomstart, ennemiesRoomstart, false, false);

	//Rooms in donjon
	std::vector<Room> roomsAdventure;
	roomsAdventure.push_back(startingRoom);
	roomsAdventure.push_back(startingRoom);
	roomsAdventure.push_back(startingRoom);

	//Donjon
	Donjon donjonAdventure(roomsAdventure, 1, 3);

	//Display(chara, player, ennemy, donjonAdventure);
}

void Display(Character chara, Player player, Ennemy ennemy, Donjon donjonAdventure)
{
	//chara
	std::cout << chara.getName() << " : \n" << "- Life : " << chara.getLife() << " / " << chara.getLife() << "\n- Force : " << chara.getForce() << "\n- Equipement : \n - -Weapon : " << chara.getWeapon().getName() << "\n - -Armor : " << chara.getArmor().getName() << "\n" << std::endl;
	//player
	std::cout << player.getName() << " : \n" << "- Life : " << player.getLife() << " / " << player.getLife() << "\n- Force : " << player.getForce() << "\n- Equipement : \n - -Weapon : " << player.getWeapon().getName() << "\n - -Armor : " << player.getArmor().getName() << "\n- Lvl : " << player.getLevel() << " / Exp : " << player.getExp() << "\n" << std::endl;
	//ennemy
	std::cout << ennemy.getName() << " : \n" << "- Life : " << ennemy.getLife() << " / " << ennemy.getLife() << "\n- Force : " << ennemy.getForce() << "\n- Equipement : \n - -Weapon : " << ennemy.getWeapon().getName() << "\n - -Armor : " << ennemy.getArmor().getName() << "\n- Exp : " << ennemy.getExp() << "\n" << std::endl;

	std::cout << "\n" << std::endl;

	//Donjon
	donjonAdventure.PrintDonjon();
}

void Choice(Donjon donjon, Player player)
{
	int choice = 0;
	std::cin >> choice;

	if (choice == 1) {
		//Observe
		//Objets cachés ?
	}
	else if (choice == 2) {
		//Change Room
		//Si 0 ennemies peut changer
	}
	else if (choice == 3) {
		//Attack
		//Si ennemies, attack un random
	}
	else if (choice == 4) {
		//Pick up
		if (donjon.getRooms()[donjon.getActualPosition()].getPotion().size() != 0)
		{
			for (size_t i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getPotion().size(); i++)
			{
				if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getUsed() == false) 
				{
					if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getForce() > 0) donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].giveForce(&player);
					else if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getLife() > 0) donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].giveLife(&player);
					else if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getHeal() > 0) donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].giveHeal(&player);

					donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].setUsed(true);
					break;
				}
			}
		}
	}
	else if (choice == 5) {
		//Sleep
		bool isEnnemiesAnymore = false;

		for (size_t i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
		{
			if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i].getLife() > 0) 
			{
				isEnnemiesAnymore = true;
			}
		}

		if (donjon.getRooms()[donjon.getActualPosition()].getBed() == true && isEnnemiesAnymore == false) 
		{
			player.Sleep((int)(player.getLifeMax() / 3));
		}
	}
	else if (choice == 6) {
		//Use
		//Les potions de soin qui sont dans pickup pour le moment, utiliser les objets dans "l'inventaire"
	}
}

int main()
{
	//Initialize();
	Choice();
}