//Exercice 13
/* Écrire un programme qui demande à l'utilisateur de taper un
entier N<=20 et qui affiche la énième ligne du triangle de Pascal.
ligne 1 : 1 1
ligne 2 : 1 2 1
ligne 3 : 1 3 3 1
ligne 4 : 1 4 6 4 1
et ainsi de suite…*/

//Manual github repos initialization test

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Timespan.h"

using namespace std;

int main() {
	Timespan d1(0, 0, 1), d2(50, 70, 1), d3(80, 30, 3);
	Timespan da(10, 5, 2), db(8, 20, 5);
	Timespan dv;
	cout << d1 << endl;
	cout << d1 + d2 << endl;
	cout << db << endl;

}
