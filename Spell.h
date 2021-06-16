#pragma once

#include <iostream>
#include <string>

class Spell
{
private:
	std::string m_name;
	int m_cost, m_dmg;
public:
	Spell();
	Spell(std::string name, int cost, int dmg);
	//~Spell();

	void show() const;
	//getters
	int getCost() const;
	int getDmg() const;
	
};

