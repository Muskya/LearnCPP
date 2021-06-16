#pragma once
#include <string>
#include "Weap.h"
#include "Spell.h"

class Character {

private:
    //Attributs
    int m_vie;
    int m_mana;
    std::string m_charName;

    Weap m_weap;
    //Spell m_spells[x]; might add later

public:
    //Constructeurs
    Character(); 
    Character(std::string charName);
    Character(std::string charName, std::string weapName,
        int weapDmg, int weapDura);

    //Destructeur(s)
    ~Character(); 

    //Méthodes
    void receiveDmg(int nbDegats);
    void attack(Character& cible);
    void magicAttack(Character& cible, Spell& spell);
    void heal(int quantitePotion);

    void changeWeap(std::string name, int dmg, int dura);

    //consts
    bool isAlive() const;
    void status() const;

};