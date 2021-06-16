#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

Character::Character() : m_vie(100), m_mana(50) {}
Character::Character(string charName) : m_charName(charName), m_vie(100),
m_mana(50) {}
Character::Character(string charName, string weapName, int weapDmg,
	int weapDura) : m_vie(100), m_mana(50), m_charName(charName), 
	m_weap(weapName, weapDmg, weapDura) 
{}

//destructor
Character::~Character() {}

//Methodes
void Character::receiveDmg(int nbDegats) {
	m_vie -= nbDegats;
	if (m_vie < 0) m_vie = 0;
}

void Character::attack(Character& cible) {
	cout << this->m_charName << " attacks " << cible.m_charName << "\n";
	cible.receiveDmg(this->m_weap.getDmg()); //weap's dmg getter
	this->m_weap.duraDmg(this->m_weap.getDmg() / 10); //dura decr when attacking
}

void Character::magicAttack(Character& cible, Spell& spell) {
	cout << this->m_charName << " throws a spell at " << cible.m_charName << "\n";
	this->m_mana -= spell.getCost();
	cible.receiveDmg(spell.getDmg());
	//add magic resistances calculations
}

void Character::changeWeap(string name, int dmg, int dura) {
	this->m_weap.swap(name, dmg, dura); //Weapon::swap(name,dmg,dura)
}

void Character::heal(int potionStrength) {
	m_vie += potionStrength;
	if (m_vie > 100) m_vie = 100;
}

bool Character::isAlive() const {
	return m_vie > 0;
}
void Character::status() const {
	if (this->isAlive()) {
		cout << "Player: " << this->m_charName << ", "
			"Health: " << this->m_vie << ", Mana: " << this->m_mana << endl;
		this->m_weap.show(); //Weapon::show()
		cout << "\n";
	}
	else {
		cout << this->m_charName << " is dead !" << endl;
	}
		
}