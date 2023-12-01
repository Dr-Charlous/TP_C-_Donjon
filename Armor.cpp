#include "Armor.h"
#include <string>


Armor::Armor(std::string _name, int _defence) :
	name(_name),
	defence(_defence) {
}

std::string Armor::getName()
{
	return this->name;
}

void Armor::setName(std::string name)
{
	this->name = name;
}

int Armor::getDefence()
{
	return this->defence;
}

void Armor::setDefence(int defence)
{
	this->defence = defence;
}
