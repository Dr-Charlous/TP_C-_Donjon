#pragma once
class Character
{
public:
    Character(int _lifeMax, int _life, int _force);

    int getLifeMax();
    void setLifeMax(int lifeMax);

	int getLife();
	void setLife(int life);

	int getForce();
	void setForce(int force);

protected :
	int lifeMax;
	int life;
	int force;
	//var inventory;
	//var weapon;
	//var armor;
};

