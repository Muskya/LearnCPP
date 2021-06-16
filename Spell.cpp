#include "Spell.h"
#include <iostream>
#include <string>

using namespace std;

Spell::Spell() {
	this->m_name = "None";
}
Spell::Spell(string name, int cost, int dmg) : m_name(name), m_cost(cost), m_dmg(dmg)
{}

void Spell::show() const {
	cout << "Spell name: " << this->m_name << ", Cost: " << this->m_cost << " mana" 
		<< ", Damage: " << this->m_dmg << endl;
}

//getters
int Spell :: getCost() const {
	return this->m_cost;
} int Spell::getDmg() const {
	return this->m_dmg;
}