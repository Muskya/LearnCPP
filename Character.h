#pragma once
#include <string>
#include "Weap.h"
#include "Spell.h"

class Character {

private:
    //Attributs "simples"
    int m_vie;
    int m_mana;
    std::string m_charName;

    //Attributs pointeurs
    Weap *m_weap;
public:
    //Constructeurs
    Character(); 
    //copy constructor
    Character(Character const& charCpy);
    Character(std::string charName, std::string weapName,
        int weapDmg);

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
    void showThisPtr() const; //returns this instance's 
    //adress with "this" ptr

    //Character& operator=(Character const& character);
};

