// TP_C++_Donjon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

#include "Character.h"
#include "Player.h"
#include "Ennemy.h"
#include "Room.h"
#include "Donjon.h"
#include "Battle.h"

class Choice;

void Observe(Donjon& donjon) {
	bool found = false;
	if (donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes().size() > 0) {
		for (size_t i = 0; i < donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes().size(); i++)
		{
			if (donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes()[i]->getGet() == false) {
				donjon.getRooms()[donjon.getActualRoom()->getName()]->addPotion(donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes()[i]);
				donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes()[i]->setGet(true);
				std::cout << "You found " << donjon.getRooms()[donjon.getActualRoom()->getName()]->getHidenOnes()[i]->getName() << "In the corner of the room." << std::endl;
				found = true;
			}
		}
	}

	if (!found) {
		std::cout << "You found nothing in the room..." << std::endl;
	}
}

bool SearchInMap(std::map<std::string, Room*> const& m, Donjon& donjon)
{
	std::string choice = "";
	std::cin >> choice;

	if (donjon.getActualRoom()->getExit() && choice == "Exit") {
		std::cout << "Congratulation you get out of the donjon !" << std::endl;
		return true;
	}

	if (m.find(choice) == m.end()) {
		std::cout << "Direction doesn't exist..." << std::endl;
		SearchInMap(m, donjon);
	}
	else {
		std::cout << "You go to the direction !" << std::endl;
		donjon.setActualRoom(donjon.getRooms()[donjon.getActualRoom()->getName()]->getRooms()[choice]);
	}
	return false;
}

bool ChangeRoom(Donjon& donjon, Player* player)
{
	bool isAnyOneAlive = false;
	for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
	{
		if (donjon.getActualRoom()->getEnnemies()[i]->getLife() > 0)
		{
			isAnyOneAlive = true;
		}
	}

	if (isAnyOneAlive)
		std::cout << "There is still ennemies !" << std::endl;
	else
	{
		for (int i = 0; i < donjon.getRooms()[donjon.getActualRoom()->getName()]->getRooms().size(); i++)
		{
			std::cout << "Direction : Room - " << i << std::endl;
		}
		if (donjon.getActualRoom()->getExit())
			std::cout << "Direction : Exit" << std::endl;

		return SearchInMap(donjon.getRooms(), donjon);
	}
}


bool RunAway(Donjon donjon, Player* player)
{
	std::srand(std::time(nullptr));
	int value = (rand() % 10) + 1;

	if (value <= 5) {
		std::cout << "You run away" << std::endl;
		return false;
	}
	else {
		std::cout << "You can't run away" << std::endl;
		return true;
	}
}

bool Attack(Donjon donjon, Player* player)
{
	int isAnyOneAlive = -1;
	for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
	{
		if (donjon.getActualRoom()->getEnnemies()[i]->isAlive())
		{
			isAnyOneAlive = i;
		}
	}

	if (isAnyOneAlive != -1) {
		Battle battle(player, donjon.getActualRoom()->getEnnemies()[isAnyOneAlive]);
		std::cout << "Fight !!!" << std::endl;
		bool battleFinished = battle.fight(player, donjon.getActualRoom()->getEnnemies()[isAnyOneAlive]);

		std::vector<Ennemy*> ennemies = donjon.getActualRoom()->getEnnemies();

		if (!ennemies[isAnyOneAlive]->isAlive()) {
			ennemies.erase(ennemies.begin() + isAnyOneAlive);
		}

		return battleFinished;
	}
	else
	{
		std::cout << "There no ennemies..." << std::endl;
		return false;
	}
}

void PickUp(Donjon donjon, Player* player)
{
	if (donjon.getActualRoom()->getPotion().size() != 0)
	{
		for (int i = 0; i < donjon.getActualRoom()->getPotion().size(); i++)
		{
			if (donjon.getActualRoom()->getPotion()[i]->getGet() == false)
			{
				if (donjon.getActualRoom()->getPotion()[i]->getForce() > 0) {
					donjon.getActualRoom()->getPotion()[i]->giveForce(player);
					donjon.getActualRoom()->getPotion()[i]->setUsed(true);
				}
				else if (donjon.getActualRoom()->getPotion()[i]->getLife() > 0) {
					donjon.getActualRoom()->getPotion()[i]->giveLife(player);
					donjon.getActualRoom()->getPotion()[i]->setUsed(true);
				}
				else if (donjon.getActualRoom()->getPotion()[i]->getHeal() > 0) {
					player->addPotionHeal(donjon.getActualRoom()->getPotion()[i]);
				}

				donjon.getActualRoom()->getPotion()[i]->setGet(true);
				break;
			}
		}

		std::cout << "No more potions here..." << std::endl;
	}
}

void Sleep(Donjon donjon, Player* player)
{
	bool isEnnemiesAnymore = false;

	for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
	{
		if (donjon.getActualRoom()->getEnnemies()[i]->getLife() > 0)
		{
			isEnnemiesAnymore = true;
			std::cout << "There is still ennemies !" << std::endl;
		}
	}

	if (donjon.getActualRoom()->getBed() == true && isEnnemiesAnymore == false)
	{
		std::cout << "Z Z Z" << std::endl;
		player->Sleep((int)(player->getLifeMax() / 3));
	}
}

void PotionUse(Player* player)
{
	if (player->getPotionHeal().size() > 0)
	{
		int usable = -1;
		for (int i = 0; i < player->getPotionHeal().size(); i++)
		{
			if (!player->getPotionHeal()[i]->getUsed())
			{
				usable = i;
			}
		}

		if (usable != -1)
		{
			std::cout << "Gloogloo... you use a " << player->getPotionHeal()[usable]->getName() << std::endl;
			player->getPotionHeal()[usable]->giveHeal(player);
			player->getPotionHeal()[usable]->setUsed(true);
			std::cout << "You healed " << player->getPotionHeal()[usable]->getHeal() << "\n" << std::endl;
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

void Choice(Donjon donjon, Player* player, bool battle)
{
#pragma region InitializeRoom
	if (battle == false)
	{
		int isAnyOneAlive = 0;
		for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
		{
			if (donjon.getActualRoom()->getEnnemies()[i]->getLife() > 0)
			{
				isAnyOneAlive++;
			}
		}

		int isAnyPotionThere = 0;
		for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
		{
			if (!donjon.getActualRoom()->getPotion()[i]->getGet())
			{
				isAnyPotionThere++;
			}
		}

		std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Room : " << donjon.getActualRoom()->getName() << "\nBed : " << donjon.getActualRoom()->getBed() << " / End : " << donjon.getActualRoom()->getExit() << "\nPotions : " << isAnyPotionThere << " / Ennemies : " << isAnyOneAlive << std::endl;
		std::cout << "\n1 : Observe \n" << "2 : Change Room \n" << "3 : Attack \n" << "4 : Pick up \n" << "5 : Sleep \n" << "6 : Use \n" << std::endl;
	}
	else
	{
		std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "2 : Change Room \n" << "3 : Attack \n" << "6 : Use \n" << std::endl;
	}
#pragma endregion InitializeRoom

#pragma region Choice
	bool isOutside = false;

	int choice = 0;
	std::cin >> choice;

	if (choice == 1 && !battle) {
		//Observe
		//Objets cachés ?
		Observe(donjon);
	}
	else if (choice == 2) {
		//Change Room
		if (!battle)
			isOutside = ChangeRoom(donjon, player);
		else
			battle = RunAway(donjon, player);
	}
	else if (choice == 3) {
		//Attack
		//Si ennemies, attack un random
		battle = Attack(donjon, player);
	}
	else if (choice == 4 && !battle) {
		//Pick up
		PickUp(donjon, player);
	}
	else if (choice == 5 && !battle) {
		//Sleep
		Sleep(donjon, player);
	}
	else if (choice == 6) {
		//Use
		//utiliser les objets dans "l'inventaire"
		PotionUse(player);
	}

	if (!isOutside) {
		Choice(donjon, player, battle);
	}

#pragma endregion Choice

#pragma region LiveCheck
	if (choice != 6 && battle) {
		int isAnyOneAlive = -1;
		for (int i = 0; i < donjon.getActualRoom()->getEnnemies().size(); i++)
		{
			if (donjon.getActualRoom()->getEnnemies()[i]->isAlive())
			{
				isAnyOneAlive = i;
				break;
			}
		}

		if (isAnyOneAlive != -1) {
			Battle battle(player, donjon.getActualRoom()->getEnnemies()[isAnyOneAlive]);

			bool battleFinished = battle.ennemyAttack(player, donjon.getActualRoom()->getEnnemies()[isAnyOneAlive]);
			Choice(donjon, player, battleFinished);
		}
	}
	else {
		//Choice(donjon, player, battle);
	}
#pragma endregion LiveCheck
}


void Initialize()
{
#pragma region Equipement
	//Weapons
	Weapon sword("Great steel sword", 15);
	Weapon dager("Little dagger", 5);

	//Armors
	Armor cloth("Cloths", 2);
	Armor steel("Steel armor", 25);
#pragma endregion Equipement
	//Characters
	Player player("Adventurer", 10000, 10000, 25, 0, 1);
	player.setWeapon(sword);
	player.setArmor(steel);

#pragma region Room0
	//Ennemies in room
	Ennemy ennemy1("ezbecuz", 1, 1, 1, 1);
	ennemy1.setWeapon(dager);
	ennemy1.setArmor(cloth);

	std::vector<Ennemy*> ennemiesRoomstart1;
	ennemiesRoomstart1.push_back(&ennemy1);

	//Potions in room
	Potion potion1("sdrgvsdr", 1, 0, 0);
	std::vector<Potion*> potionRoomstart1;
	potionRoomstart1.push_back(&potion1);

	//Room
	Room Room0("Room0", potionRoomstart1, ennemiesRoomstart1, true, false);
#pragma endregion Room0

#pragma region Room1
	//Ennemies in room
	Ennemy ennemy2("ezbecuz", 1, 1, 1, 1);
	std::vector<Ennemy*> ennemiesRoomstart2;
	ennemiesRoomstart2.push_back(&ennemy2);

	//Potions in room
	Potion potion2("sdrgvsdr", 1, 0, 0);
	std::vector<Potion*> potionRoomstart2;
	potionRoomstart2.push_back(&potion2);

	//Room
	Room Room1("Room1", potionRoomstart2, ennemiesRoomstart2, false, true);
#pragma endregion Room1

#pragma region Donjon
	//Rooms in rooms
	Room0.addRooms(&Room1);
	Room1.addRooms(&Room0);

	//Rooms in donjon
	std::map<std::string, Room*> roomsAdventure;
	roomsAdventure[Room0.getName()] = &Room0;
	roomsAdventure[Room1.getName()] = &Room1;

	//Donjon
	Donjon donjonAdventure(&Room1);
	donjonAdventure.setRooms(roomsAdventure);
#pragma endregion Donjon

	Choice(donjonAdventure, &player, false);
}

int main()
{
	std::cout << "You wake up in a mysteriuos dungeon... what append ?" << std::endl;

	Initialize();
}