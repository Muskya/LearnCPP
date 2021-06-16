#pragma once
#include <string>

class Weap
{
private:
	std::string m_name;
	int m_dmg, m_dura;

public:
	~Weap();
	Weap();
	Weap(std::string name, int dmg, int dura);

	void swap(std::string name, int dmg, int dura);
	void show() const; //name, dmg, durability
	void duraDmg(float duraDmg);

	int getDmg() const;
	int getDura() const;

};

