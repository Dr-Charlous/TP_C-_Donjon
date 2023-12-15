#pragma once
#include "Player.h"
#include "Ennemy.h"
class Battle
{
public :
	Battle(Player* player, Ennemy* ennemy);

	Player* getPlayer();
	void setPlayer(Player* player);

	Ennemy* getEnnemy();
	void setEnnemy(Ennemy* ennemy);

	bool fight(Player* player, Ennemy* ennemy);
	bool ennemyAttack(Player* player, Ennemy* ennemy);
protected :
	Player* player;
	Ennemy* ennemy;
};

