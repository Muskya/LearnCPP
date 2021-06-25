//Exercice 15
/*  */

//standard library headers
#include <iostream> 
#include <string>
#include <vector>

//user-created headers
#include "GlobalFunctions.h"
#include "Character.h"
#include "Timespan.h"

using namespace std;

class Vehicule {
protected:
    int m_prix;
public:
    Vehicule(int prix = 0) : m_prix(prix) {}
    virtual ~Vehicule() {} //does nothing for now
    virtual void affiche() const {
        cout << "Je suis un vehicule." << endl;
    }
};

class Voiture : public Vehicule {
private:
    int m_portes;
public:
    //we call Vehicule (base class) constructor with a price
    Voiture(int prix, int portes = 2) : Vehicule(prix), m_portes(portes) {} 
    virtual ~Voiture() {} //does nothing for now
    void affiche() const { //virtual here only helps with readability
        cout << "Je suis une voiture." << endl;
    }
};

class Moto : public Vehicule {
private:
    double m_vitesse;
public:
    Moto(int prix, double speed) : Vehicule(prix), m_vitesse(speed) {}
    virtual ~Moto() {}
    void affiche() const {
        cout << "Je suis une moto." << endl;
    }
};

void sePresenter(Vehicule *v) { //can be Vehicule, Voiture, Moto....
    v->affiche();
}

int main() {
    //Classes faites directement dans le main sans de headers 
    //pour que ce soit plus clair lors de la mise en application de 
    //l'héritage / polymorphisme.

    Vehicule* v, * m, * vo;
    v = new Vehicule(13000);
    m = new Moto(7500, 130.5);
    vo = new Voiture(34000, 5);

    cout << "Affichage avec affiche() (in-class): " << endl;
    v->affiche(); m->affiche(); vo->affiche(); 
    cout << "Affichage avec sePresenter() en passant un pointeur Vehicule en param: " << endl;
    sePresenter(v); sePresenter(m); sePresenter(vo);
    cout << "\n";

    vector<Vehicule*> listeVehicules;
    listeVehicules.push_back(v);
    listeVehicules.push_back(m);
    listeVehicules.push_back(vo);
    listeVehicules.push_back(new Moto(9500, 213.6));
    listeVehicules.push_back(new Vehicule(10000));
    listeVehicules.push_back(new Voiture(15000, 4));

    cout << "Affichage sePresenter() (out-of-class) en bouclant sur le vecteur véhicules: " << endl;
    for (int i = 0; i < listeVehicules.size(); i++) {
        sePresenter(listeVehicules[i]);
    }

    cout << "\n Affichage affiche() (in-class) en bouclant sur le vecteur véhicules: " << endl; 
    for (int i = 0; i < listeVehicules.size(); i++) {
        listeVehicules[i]->affiche();
    }

    //pointers deletion loop
    for (int i = 0; i < listeVehicules.size(); i++) {
        delete listeVehicules[i];
        listeVehicules[i] = 0; //précaution supplémentaire
    }
}








