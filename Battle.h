#pragma once
#include "Player.h"
#include "Ennemy.h"
class Battle
{
public :
	Battle(Player player, Ennemy ennemy);

	Player* getPlayer();
	void setPlayer(Player* player);

	Ennemy* getEnnemy();
	void setEnnemy(Ennemy* ennemy);

	void fight();
protected :
	Player* player;
	Ennemy* ennemy;
};

