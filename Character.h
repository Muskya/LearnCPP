#pragma once
#include <string>
#include "Weap.h"
#include "Spell.h"

class Character {

private:
    int m_vie;
    int m_mana;
    std::string m_charName;
    Weap *m_weap;
public:
    //Constructeurs/destructeurs
    Character(); 
    //copy constructor
    Character(Character const& charCpy);
    Character(std::string charName, std::string weapName,
        int weapDmg);
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
    void showThisPtr() const; /*returns this instance's 
    adress with "this" ptr */

    //operators
    /*"operator=" overload is needed when copy constructor
    has been overloaded in the first place*/
    Character& operator=(Character const& character);
};

