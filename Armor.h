#pragma once
#include <string>
class Armor
{
public :
	Armor(std::string name, int defence);

	std::string getName();
	void setName(std::string name);

	int getDefence();
	void setDefence(int defence);

protected:
	std::string name;
	int defence;
};

