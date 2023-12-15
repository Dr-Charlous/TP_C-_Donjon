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
#include "Battle.h"

void Choice(Donjon donjon, Player* player, bool battle)
{
	if (battle == false)
	{
		int isAnyOneAlive = 0;
		for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
		{
			if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i]->getLife() > 0)
			{
				isAnyOneAlive++;
			}
		}

		std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Room : " << donjon.getActualPosition() << "\nBed : " << donjon.getRooms()[donjon.getActualPosition()].getBed() << " / End : " << donjon.getRooms()[donjon.getActualPosition()].getExit() << "\nPotions : " << donjon.getRooms()[donjon.getActualPosition()].getPotion().size() << " / Ennemies : " << isAnyOneAlive << std::endl;
		std::cout << "\n1 : Observe \n" << "2-5 : Change Room \n" << "6 : Attack \n" << "7 : Pick up \n" << "8 : Sleep \n" << "9 : Use \n" << std::endl;
	}
	else
	{
		std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "2-5 : Change Room \n" << "6 : Attack \n" << "9 : Use \n" << std::endl;
	}

	int choice = 0;
	std::cin >> choice;

	if (choice == 1 && !battle) {
		//Observe
		//Objets cachés ?
		std::cout << "You see nothing..." << std::endl;
	}
	else if (choice >= 2 && choice <= 5) {
		//Change Room
		if (!battle)
		{
			bool isAnyOneAlive = false;
			for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
			{
				if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i]->getLife() > 0)
				{
					isAnyOneAlive = true;
				}
			}

			if (isAnyOneAlive)
				std::cout << "There is still ennemies !" << std::endl;
			else
				std::cout << "You can go" << std::endl;
		}
		else {
			std::srand(std::time(nullptr));
			int value = (rand() % 10) + 1;

			if (value <= 5) {
				std::cout << "You can run away" << std::endl;
			}
			else {
				std::cout << "You can't run away" << std::endl;
			}
		}



		// peut changer room
	}
	else if (choice == 6) {
		//Attack
		//Si ennemies, attack un random
		int isAnyOneAlive = -1;
		for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
		{
			if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i]->isAlive())
			{
				isAnyOneAlive = i;
			}
		}

		if (isAnyOneAlive != -1) {
			Battle battle(player, donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[isAnyOneAlive]);
			std::cout << "Fight !!!" << std::endl;
			bool battleFinished = battle.fight(player, donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[isAnyOneAlive]);

			Choice(donjon, player, battleFinished);
		}
		else
		{
			std::cout << "There no ennemies..." << std::endl;
		}
	}
	else if (choice == 7 && !battle) {
		//Pick up
		if (donjon.getRooms()[donjon.getActualPosition()].getPotion().size() != 0)
		{
			for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getPotion().size(); i++)
			{
				if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getUsed() == false)
				{
					if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getForce() > 0) donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].giveForce(player);
					else if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getLife() > 0)  donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].giveLife(player);
					else if (donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getHeal() > 0) player->addPotionHeal(donjon.getRooms()[donjon.getActualPosition()].getPotion()[i]);

					donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].setUsed(true);
					std::cout << "You get a " << donjon.getRooms()[donjon.getActualPosition()].getPotion()[i].getName() << std::endl;
					break;
				}
			}

			std::cout << "No more potions here..." << std::endl;
		}
	}
	else if (choice == 8 && !battle) {
		//Sleep
		bool isEnnemiesAnymore = false;

		for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
		{
			if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i]->getLife() > 0)
			{
				isEnnemiesAnymore = true;
				std::cout << "There is still ennemies !" << std::endl;
			}
		}

		if (donjon.getRooms()[donjon.getActualPosition()].getBed() == true && isEnnemiesAnymore == false)
		{
			std::cout << "Z Z Z" << std::endl;
			player->Sleep((int)(player->getLifeMax() / 3));
		}
	}
	else if (choice == 9) {
		//Use
		//utiliser les objets dans "l'inventaire"
		if (player->getPotionHeal().size() > 0)
		{
			int usable = -1;
			for (int i = 0; i < player->getPotionHeal().size(); i++)
			{
				if (!player->getPotionHeal()[i].getUsed())
				{
					usable = i;
				}
			}

			if (usable != -1)
			{
				std::cout << "Gloogloo... you use a " << player->getPotionHeal()[usable].getName() << std::endl;
				player->getPotionHeal()[usable].giveHeal(player);
			}
			else
			{
				std::cout << "No more potions in your pockets..." << std::endl;
			}
		}
		else {
			std::cout << "No potions in your pockets..." << std::endl;
		}
	}

	if (player->isAlive()) {
		if (choice != 6 && battle) {
			int isAnyOneAlive = -1;
			for (int i = 0; i < donjon.getRooms()[donjon.getActualPosition()].getEnnemies().size(); i++)
			{
				if (donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[i]->isAlive())
				{
					isAnyOneAlive = i;
					break;
				}
			}

			if (isAnyOneAlive != -1) {
				Battle battle(player, donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[isAnyOneAlive]);

				bool battleFinished = battle.ennemyAttack(player, donjon.getRooms()[donjon.getActualPosition()].getEnnemies()[isAnyOneAlive]);
				Choice(donjon, player, battleFinished);
			}
		}
		else {
			Choice(donjon, player, battle);
		}
	}
	else
		std::cout << "\nYou lose... try again !" << std::endl;
}


void Initialize()
{
	//Weapons
	Weapon sword("Great steel", 10);
	Weapon dager("Little man", 5);

	//Armors
	Armor cloth("Just cloths", 2);
	Armor steel("Steel armor", 25);

	//Potions
	Potion potion("Heal potion", 10, 0, 0, false);

	//Characters
	Player player("Adventurer", 10000, 10000, 25, sword, steel, 0, 1);
	Ennemy ennemy1("Goblin", 100, 100, 25, dager, cloth, 10);
	Ennemy ennemy2("Goblin", 100, 100, 25, dager, cloth, 10);

	//Potions in room
	std::vector<Potion> potionRoomstart;
	potionRoomstart.push_back(potion);
	potionRoomstart.push_back(potion);

	//Ennemies in room
	std::vector<Ennemy*> ennemiesRoomstart;
	ennemiesRoomstart.push_back(&ennemy1);
	ennemiesRoomstart.push_back(&ennemy2);

	//Room
	Room startingRoom(potionRoomstart, ennemiesRoomstart, false, false);

	//Rooms in donjon
	std::vector<Room> roomsAdventure;
	roomsAdventure.push_back(startingRoom);
	roomsAdventure.push_back(startingRoom);
	roomsAdventure.push_back(startingRoom);

	//Donjon
	Donjon donjonAdventure(roomsAdventure, 1, 3);


	//Display(chara, player, ennemy, donjonAdventure);
	Choice(donjonAdventure, &player, false);
}

int main()
{
	Initialize();
}