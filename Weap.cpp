#include "Weap.h"
#include <string>
#include <iostream>

using namespace std;

Weap::~Weap() {}
Weap::Weap() : m_name("None"), m_dmg(0), m_dura(0) {}
Weap::Weap(string weapName, int weapDmg, int dura) : m_name(weapName),
m_dmg(weapDmg), m_dura(dura) {}

void Weap::swap(string name, int dmg, int dura) {
	m_name = name; m_dmg = dmg; m_dura = dura;
}
void Weap::show() const {
	cout << "Weapon: " << m_name << ", Damage: " << m_dmg
		<< ", Durability: " << m_dura << endl;
}
void Weap::duraDmg(float duraDmg) {
	this->m_dura -= duraDmg;
}

//getters setters
int Weap::getDmg() const {
	return m_dmg;
}
int Weap::getDura() const {
	return m_dura;
}